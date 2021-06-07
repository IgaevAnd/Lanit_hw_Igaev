Action()
{
	
	lr_start_transaction("UC_Read_mail_script_transaction");
	
	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_reg_find("Text=Авторизация", 
		LAST);

	web_add_auto_header("DNT", 
		"1");
	
	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

/*Correlation comment - Do not change!  Original value='b02b38c1f6a03239415e4dab0a3f1d21031612f0:1622817012890' Name ='csrf_token' Type ='Manual'*/
	web_reg_save_param_attrib(
		"ParamName=csrf_token",
		"TagName=input",
		"Extract=value",
		"Name=csrf_token",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=Yes",
		"RequestUrl=*/passport*",
		LAST);

/*Correlation comment - Do not change!  Original value='d9155468-6d9e-447e-a8f2-b38e07a718ec' Name ='process_uuid' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=process_uuid",
		"RegExp=process_uuid=(.*?)\"\\ class",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/passport*",
		LAST);

	web_url("lite", 
		"URL=https://mail.yandex.ru/lite", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t355.inf", 
		"Mode=HTML", 
		LAST);

	

	lr_start_transaction("UC01_Login_transaction");

	authorization_func();

	lr_end_transaction("UC01_Login_transaction",LR_AUTO);
	


	lr_start_transaction("UC02_Inbox_transaction");

	web_reg_find("Text=Входящие", 
		LAST);

	web_reg_save_param_regexp(
		"ParamName=Message_id",
		"RegExp=(\\d+)\\/new\" class",
		"NotFound=warning",
		"Group=1",
		"Ordinal=all",
		SEARCH_FILTERS,
		"Scope=BODY",
		LAST);

	web_url("inbox", 
		"URL=https://mail.yandex.ru/lite/inbox", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://mail.yandex.ru/lite", 
		"Snapshot=t399.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC02_Inbox_transaction", LR_AUTO);

	
	

    if ( atoi(lr_eval_string("{Message_id_count}")) == 0 )
    {
         lr_output_message( "Inbox is EMPTY!" );
    }
    else{

    random_func();
	



	lr_start_transaction("UC03_Go_To_Mail_transaction");

	web_reg_find("Text=Входящие", 
		LAST);

/*Correlation comment - Do not change!  Original value='fmU7aWp1xysKgjPs7IOfK0WxW7o=!kpjuw749' Name ='_ckey' Type ='Manual'*/
	web_reg_save_param_attrib(
		"ParamName=_ckey",
		"TagName=input",
		"Extract=value",
		"Name=_ckey",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		LAST);

	web_url("new",
		"URL=https://mail.yandex.ru/lite/message/{Message_id_random}/new",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://mail.yandex.ru/lite/inbox",
		"Snapshot=t410.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("UC03_Go_To_Mail_transaction",LR_AUTO);

	
	
	lr_start_transaction("UC04_Redirect_Mail_transaction");

	web_reg_find("Text=Входящие", 
		LAST);

/*Correlation comment - Do not change!  Original value='zsKwsIMw5ww4jGnvocS6ttyVcsw=!kpjuwrkm' Name ='_ckey_1' Type ='Manual'*/
	web_reg_save_param_attrib(
		"ParamName=_ckey_1",
		"TagName=input",
		"Extract=value",
		"Name=_ckey",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=Yes",
		"RequestUrl=*/message-menu*",
		LAST);

	web_submit_data("message-action.xml",
		"Action=https://mail.yandex.ru/lite/message-action.xml",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=https://mail.yandex.ru/lite/message/{Message_id_random}/new",
		"Snapshot=t421.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=ids", "Value={Message_id_random}", ENDITEM,
		"Name=lids", "Value=12,14,15,FAKE_MULCA_SHARED_LBL,FAKE_RECENT_LBL,FAKE_SEEN_LBL", ENDITEM,
		"Name=_handlers", "Value=do-messages", ENDITEM,
		"Name=_ckey", "Value={_ckey}", ENDITEM,
		"Name=retpath", "Value=message/{Message_id_random}", ENDITEM,
		"Name=folder_retpath", "Value=folder/1", ENDITEM,
		"Name=delete_retpath", "Value=folder/1", ENDITEM,
		"Name=more", "Value=Ещё…", ENDITEM,
		"Name=request", "Value=", ENDITEM,
		LAST);

	web_reg_find("Text=Прочитано", 
		LAST);

	web_submit_data("message-menu-action.xml",
		"Action=https://mail.yandex.ru/lite/message-menu-action.xml",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=https://mail.yandex.ru/lite/message-menu?retpath=message%2F{Message_id_random}&delete_retpath=folder%2F1&count=1&ids={Message_id_random}&folder_retpath=folder%2F1&lids=12%2C14%2C15%2CFAKE_MULCA_SHARED_LBL%2CFAKE_RECENT_LBL%2CFAKE_SEEN_LBL&",
		"Snapshot=t433.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=_ckey", "Value={_ckey_1}", ENDITEM,
		"Name=ids", "Value={Message_id_random}", ENDITEM,
		"Name=_handlers", "Value=do-messages", ENDITEM,
		"Name=retpath", "Value=message/{Message_id_random}", ENDITEM,
		"Name=count", "Value=1", ENDITEM,
		"Name=folder_retpath", "Value=folder/1", ENDITEM,
		"Name=delete_retpath", "Value=folder/1", ENDITEM,
		"Name=movefile", "Value=7", ENDITEM,
		"Name=lid", "Value=", ENDITEM,
		"Name=unlid", "Value=", ENDITEM,
		"Name=move", "Value=Выполнить", ENDITEM,
		LAST);

	lr_end_transaction("UC04_Redirect_Mail_transaction",LR_AUTO);


	

	lr_start_transaction("UC05_Go_Inbox_transaction");

	web_reg_find("Text=Входящие", 
		LAST);

	web_url("inbox_2",
		"URL=https://mail.yandex.ru/lite/inbox",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://mail.yandex.ru/lite/message/{Message_id_random}?executed_action=move&unlid=&count=1&lid=&fid=7&",
		"Snapshot=t443.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("UC05_Go_Inbox_transaction",LR_AUTO);
	}
    
	lr_end_transaction("UC_Read_mail_script_transaction",LR_AUTO);
    
    
	return 0;
}