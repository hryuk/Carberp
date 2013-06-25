Отключается фаервол винды (сервис SharedAccess)

Добавляет нового юзера "TermUser" с паролем "TMPass123", и добавлет его в группу
админов (DOMAIN_ALIAS_RID_ADMINS) и в группу юзеров имеющих доступ к RDP (DOMAIN_ALIAS_RID_REMOTE_DESKTOP_USERS)

копирует файлы из папки Bin:
BETWINKF.SYS ->	"system32\Drivers\BETWINKF.SYS"
BETWINMF.SYS -> "system32\Drivers\BETWINMF.SYS"
BeTwinSystem.SYS -> "system32\Drivers\BeTwinSystem.SYS"
BETWINVF.SYS ->	"system32\Drivers\BETWINVF.SYS"
BeTwinServiceXP.exe -> "system32\BeTwinServiceXP.exe"
SlsApi.dll -> "system32\SlsApi.dll"
oemsetup.ini ->	"system32\oemsetup.ini"

переименовывает "system32\xtgina.dll" на "system32\xtgina.old", и заменяет "system32\xtgina.dll"
своим xtgina.dll из папки Bin.

ищет файл "system32\winscard32.dll", если нет, то переименовывает "system32\winscard.dll" в 
"system32\winscard32.dll" (видать "system32\winscard32.dll" есть только в 64-х разрядных осях)
если есть, то переименовывает в "system32\winscard.dll" на "system32\winscard.old"
потом копирует свой winscard_32.dll из Bin в "system32\winscard.dll".
Перед тем как заменить "system32\winscard32.dll" отключается на минуту защита от замены системных файлов
(используется недокументированная функция SfcFileException из sfc_os.dll.

И в конце в реестр импотируется файл reg.reg.
reg.reg содержит ключи реестра для регистрации скопированных драйверов


