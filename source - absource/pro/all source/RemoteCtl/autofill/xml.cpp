// xml parser (XELP) v1.0.4

// 17.12.2008
// 19.12.2008
// 25.12.2008
// 10x to elki

#include "std.h"

void *xalloc(size_t size)
{
    return HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,size);
}

void xfree(void *mem)
{
    HeapFree(GetProcessHeap(),0,mem);
    return;
}

/*	================================
	== MemAddMem
	================================	*/
char *MemAddMem (char *pch, unsigned long len)
{
    char *ret = 0;

    if (!(pch || *pch))
        return 0;

    if (!len)
        return 0;
    ret = (char*)xalloc(len + 1);
    if (!ret) return 0;

    memcpy(ret,pch,len);

    return ret;
}

/*	================================
	== XmlIsChar
	================================	*/
bool XmlIsChar(char ch, unsigned long type)
{

#define SPACE		0x01
#define USELESS		0x02
#define APOSTROPHE	0x04
#define LETTERS		0x08
#define NUMBER		0x10

    bool ret = false;

    if (type & SPACE)
        switch (ch)
        {
        case '\t':
        case '\0':
        case '\n':
        case '\r':
        case ' ':
//			case '\xff': ; буква 'я'
            ret = true;
        }

    if (!ret && type & USELESS)
        switch (ch)
        {
        case '!':
        case '?':
            ret = true;
        }

    if (!ret && type & APOSTROPHE)
        switch (ch)
        {
        case '"':
        case '\'':
            ret = true;
        }


    if (!ret && type & LETTERS)
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            ret = true;

    if (!ret && type & NUMBER)

        if ((ch >= '0' && ch <= '9'))
            ret = true;

    return ret;
}

/*	================================
	== XmlGetParameters
	================================	*/
bool XmlGetParameters(PNODE node, char *data, unsigned long len)
{

#define GRAB_NOT	0x00
#define GRAB__PARAM	0x01
#define GRAB_VALUE	0x02

    ULONG i,size;
    ULONG status = 0;
    ULONG end_value = 0;
    PCHAR tmp;
    PPARAM param,prev = 0;

    if (!node || !data || !len)
        return false;

    for (size = 0,i = 1; i < len; i ++)
    {

//			if (data[i] == '>')
//				break;

        if (status != GRAB_VALUE && data[i] == '/')
        {
            node->simply = true;
            break;
        }

        if (status == GRAB_NOT && XmlIsChar(data[i],SPACE))
        {
            status = GRAB__PARAM;
            size = 0;
            continue;
        }

        if (status == GRAB__PARAM && data[i] == '=')
        {
            status = GRAB_VALUE;

            if (!(tmp = MemAddMem(&data[i - size],size)))
                return false;

            size = 0;
            param = (PPARAM)xalloc(sizeof(_PARAM));
            param->name = tmp;
            param->dwnamehash = CalcFuncCRC32i((byte*)tmp);

            //XML_DBG("XmlGetParameters(): param:'%s'\n",param->name);
            continue;
        }


        if (status == GRAB_VALUE)

            if (!end_value)
                if (XmlIsChar(data[i],APOSTROPHE))
                {
                    end_value = APOSTROPHE;
                    continue;

                }
                else
                    end_value = SPACE;

            else if (XmlIsChar(data[i],end_value))
            {
                status = GRAB__PARAM;

                param->value = MemAddMem(&data[i - size],size);
                size = 0;

                if (prev)
                {
                    prev->next = param;
                    param->prev = prev;
                }
                else
                    node->param = param;

                prev = param;

                //XML_DBG("XmlGetParameters(): value:'%s'\n",param->value);
                end_value = 0;

                continue;
            }

        if (status == GRAB__PARAM && XmlIsChar(data[i],SPACE))
            continue;

        size ++;
    }


    //XML_DBG("\n");

    return true;
}

ULONG XmlParse( PNODE root, PCHAR data, ULONG len, PNODE* handle)
{

#define NOTHING		0x00
#define FIND_CLOSE	0x01
#define FIRST_BYTE	0x02
#define USELESS_TAG	0x04
#define TAG_FOUND	0x08
#define CLOSE_TAG	0x10
#define GRAB_NAME	0x20

    ULONG status = NOTHING;
    ULONG i,j,val_len;
    ULONG size = 0,ret;
    ULONG have_tag = false;
    PCHAR start;
    PCHAR name;
    PNODE node,prev = 0;
    int dwnamehash=0;

    if (!data || !len)
        return 0;

    for (i = 0; i < len; i ++)
    {

        if (data[i] == '<')
        {

            //XML_DBG("XmlParse(): tag open\n");

            if (status & FIND_CLOSE)
            {
                //XML_DBG("XmlParse(): open new tag in non-closed tag\n");
                return 0;
            }

            status = FIND_CLOSE|FIRST_BYTE;
            start = &data[i];
            continue;
        }

        if (status & FIRST_BYTE)
        {

            //XML_DBG("XmlParse(): FIRST_BYTE\n");

            if (XmlIsChar(data[i],USELESS))
            {
                status |= USELESS_TAG;
                //XML_DBG("XmlParse(): USELESS_TAG found\n");
            }

            else if (data[i] == '/')
            {
                status |= CLOSE_TAG;
                //XML_DBG("XmlParse(): closed ted found\n");
                continue;
            }

            else if (!XmlIsChar(data[i],LETTERS|NUMBER))
            {
                //XML_DBG("XmlParse(): invalid tag name\n");
                return 0;
            }

            status ^= FIRST_BYTE;

            if (!(status & CLOSE_TAG))
                have_tag = true;

            if (!(status & USELESS_TAG))
            {
                status |= GRAB_NAME;
                size = 0;
                name = 0;
            }
            continue;
        }

        if (status & GRAB_NAME)
        {

            size ++;

            if (XmlIsChar(data[i],SPACE) || data[i] == '>')
            {

                //XML_DBG("XmlParse(): GRAB_NAME\n");

                status ^= GRAB_NAME;

                if (!(name = MemAddMem(&data[i - size],size)))
                    return 0;

                dwnamehash = CalcFuncCRC32i((byte*)name);
            }
        }

        if ((status & FIND_CLOSE) && data[i] == '>')
        {

            //XML_DBG("XmlParse(): found end of tag\n");

            status ^= FIND_CLOSE;
            status |= TAG_FOUND;
            i ++;

        }

        if (status & TAG_FOUND)
        {

            //XML_DBG("XmlParse(): tag found\n");

            if (status & USELESS_TAG)
            {
                //XML_DBG("XmlParse(): useless tag, continue\n\n");
                status = NOTHING;
                continue;
            }

            if ((status & CLOSE_TAG))
            {

                //XML_DBG("XmlParse(): CLOSE_TAG '%s'\n",name);

                if (!have_tag)
                {

                    val_len = start - data;

                    for (j = 0; j < val_len; j ++)
                        if (!XmlIsChar(data[j],SPACE))
                            break;

                    do
                        -- val_len;
                    while (XmlIsChar(data[val_len],SPACE));

                    root->value = (char*)xalloc(val_len - j + 2);
                    memcpy(root->value,&data[j],val_len - j + 1);

                    //XML_DBG("XmlParse(): NODE:'%s' value '%s'\n",root->name,root->value);
                }

                if (dwnamehash==root->dwnamehash)
                {
                    //if (!strcmp(root->name,name)) {
                    //XML_DBG("XmlParse(): found end of node '%s'\n\n",name);
                    return i;
                }
                else
                {
                    //XML_DBG("XmlParse(): root tag have another name '%s'\n",root->name);
                    return 0;
                }
            }

            status = NOTHING;

            node = (PNODE) xalloc(sizeof(_NODE));
            node->name = name;
            node->dwnamehash=dwnamehash;

            //XML_DBG("XmlParse(): NODE:'%s'\n",node->name);

            if (!XmlGetParameters(node,start,&data[i] - start))
                return 0;

            if (prev)
            {
                prev->next = node;
                node->prev = prev;
            }
            else if (root)
                root->child = node;
            else
                *handle = node;

            if (!node->simply)
                if (!(ret = XmlParse(node,&data[i],len - i,0)))
                    return 0;
                else
                    i += ret-1;

            prev = node;

            continue;
        }

    }
    return i;
}

/*	================================
	== XmlParse
	================================	*/
ULONG XmlParse(PCHAR data, ULONG len,PNODE* handle)
{
    return XmlParse(0,data,len,handle);
}

/*	================================
	== XmlFree
	================================	*/
void XmlFree(PNODE *pnode)
{
    PPARAM param;
    PNODE prev,node=*pnode;

    if (!node)
        return;

    do
    {
        if ((param = node->param))
            while ((param = param->next))
                xfree(param->prev);

        if (node->value)
            xfree(node->value);

        if ((node->child))
            XmlFree(&node->child);

        prev = node;
        node = node->next;
        xfree(prev);

    }
    while (node);
    *pnode=0;
}

/*	================================
	== XmlDuplicateNode
	================================	*/
PNODE XmlDuplicateNode(PNODE node)
{
    PPARAM param;

    if (!node)
        return NULL;

    PNODE rootnode = (PNODE) xalloc(sizeof(_NODE)),
          newnode = rootnode,
          prev = 0;

    if (!newnode)
        return NULL;

    do
    {
        if ((param = node->param))
        {
            while ((param = param->next))
            {
                newnode->param->name = MemAddMem(param->prev->name,strlen(param->prev->name));
                if (!newnode->param->name)
                {
                    XmlFree(&rootnode);
                    return NULL;
                }
                newnode->param->dwnamehash = param->prev->dwnamehash;
                newnode->param->value = MemAddMem(param->prev->value,strlen(param->prev->value));
                if (!newnode->param->value)
                {
                    XmlFree(&rootnode);
                    return NULL;
                }
            }
        }

        if (node->value)
            newnode->value = MemAddMem(node->value,strlen(node->value));

        if (node->name)
            newnode->name = MemAddMem(node->name,strlen(node->name));

        if ((node->child))
            newnode->child = XmlDuplicateNode(node->child);

        newnode->dwnamehash = node->dwnamehash;
        newnode->simply = node->simply;

        node = node->next;
        if (node)
        {
            prev = newnode;
            newnode->next = (PNODE) xalloc(sizeof(_NODE));
            if (!newnode)
            {
                XmlFree(&rootnode);
                return NULL;
            }
            newnode = newnode->next;
            newnode->prev = prev;

        }
    }
    while (node);

    return rootnode;
}

/*	================================
	== XmlGetSubNodeValueByName
	================================	*/
char *XmlGetSubNodeValueByName(PNODE node, char *name)
{
    if (!node)
        return 0;

    if (!(node = node->child))
        return 0;

    int dwnamehash = CalcFuncCRC32i((byte *)name);

    for (; node; node = node->next)
    {

        if (!node->name)
            continue;

        //if (!strcmpi(node->name,name))
        if (dwnamehash==node->dwnamehash)
            return node->value;

    }

    return 0;
}

/*	================================
	== XmlEnumerateSubNodes
	================================	*/
PNODE XmlEnumerateSubNodes(PNODE node, unsigned long idx)
{
    unsigned long i;

    if (!node)
        return 0;

    if (!(node = node->child))
        return 0;

    for (i = 0; node; node = node->next,i ++)
    {

        if (i != idx)
            continue;

        return node;
    }

    return 0;
}

/*	================================
	== XmlGetSubNodeByName
	================================	*/
PNODE XmlGetSubNodeByName(PNODE node, char *name)
{
    if (!node)
        return 0;

    if (!(node = node->child))
        return 0;

    int dwnamehash = CalcFuncCRC32i((byte *)name);

    for (; node; node = node->next)
    {
        if (!node->name)
            continue;

        //if (!strcmpi(node->name,name))
        if (dwnamehash==node->dwnamehash)
            return node;
    }

    return 0;
}

/*	================================
	== XmlGetNextSubNodeByName
	================================	*/
PNODE XmlGetNextSubNodeByName(PNODE node, char *name)
{
    if (!node)
        return 0;

    if (!(node = node->next))
        return 0;

    int dwnamehash = CalcFuncCRC32i((byte *)name);

    for (; node; node = node->next)
    {
        if (!node->name)
            continue;

        //if (!strcmpi(node->name,name))
        if (dwnamehash==node->dwnamehash)
            return node;
    }

    return 0;
}

/*	================================
	== XmlGetValueByParameterName
	================================	*/
char * XmlGetValueByParameterName(PNODE node, char *name)
{
    PPARAM param;

    if (!node)
        return 0;

    if (!(param = node->param))
        return 0;

    int dwnamehash = CalcFuncCRC32i((byte *)name);

    for (; param; param = param->next)
    {

        if (!param->name)
            continue;

        //if (!strcmpi(param->name,name))
        if (dwnamehash==param->dwnamehash)
            return param->value;
    }

    return 0;
}

