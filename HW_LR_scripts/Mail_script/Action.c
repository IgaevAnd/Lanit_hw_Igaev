Action()
{

	lr_start_transaction("UC_Mail_script_transaaction");
	
	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_reg_find("Text=Авторизация", 
		LAST);

	web_add_auto_header("DNT", 
		"1");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");



	/*Correlation comment - Do not change!  Original value='6c2b7d759d6f547c1b52e908f725b024b78c6fc7:1622726351726' Name ='csrf_token' Type ='Manual'*/
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

	/*Correlation comment - Do not change!  Original value='e2cff81a-d6a1-453e-a165-4e278c85c218' Name ='process_uuid' Type ='Manual'*/
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
		"Snapshot=t388.inf", 
		"Mode=HTML", 
		LAST);
	
	
	lr_start_transaction("UC01_Login_transaction");	

	authorization_func();
	
	lr_end_transaction("UC01_Login_transaction",LR_AUTO);
	
		
	lr_start_transaction("UC02_Send_transaction");

	send_mail_func();

	lr_end_transaction("UC02_Send_transaction",LR_AUTO);
	
	
	lr_end_transaction("UC_Mail_script_transaaction",LR_AUTO);

	return 0;
}