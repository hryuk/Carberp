// ---------------------------------------------------------------------------
//  Константы модуля мониторинга систем бота
// ---------------------------------------------------------------------------

#ifndef BotMonitorConstsH
#define BotMonitorConstsH
// ---------------------------------------------------------------------------

// Константы для работы с монитором бота
namespace BotMonitor
{
    // Имя серверной части монитора
	const static char ServerName[] = "BTMonitor_Server";

	// Имя клиентской части монитора
	const static char ClientName[] = "BTMonitor_Client";

	// Имена процессов в которых будет запускаться монитор
	const static char ProcessExplorer[] = "explorer";
	const static char ProcessLoader[]   = "loader";



	//-------------- Константы ---------------------//

	// бот отправляем каб архив в админку
	// формат: ИМФ_СИСТЕМЫ:ИМЯ_ФАЙЛА
	const static char MessageSendCab[] = "senddata_cab";

	// Ошибка отправки каб файла
	const static char MessageSendCabError[] = "senddata_error_cab";



	// Команды менеджера задач
    const static char TaskNoCommands[]    = "task_no_commands"; // Команды отсутствуют
	const static char TaskExecCommandOk[] = "task_cmd_exec_ok"; // Команда успешно выполнена
	const static char TaskExecCommandEr[] = "task_cmd_exec_er"; // Команда не выполнена


	// Константы конфигов
	const static char ConfigLoadFile[]    = "config_load_file"; // Отправитель загружает конфиг из файла
	const static char ConfigMaskExec[]    = "config_mask_exec"; // Сработала маска
	const static char ConfigDataExec[]    = "config_data_exec"; // Сработали данные
}


// ---------------------------------------------------------------------------
#endif
