send_mail_func(){
	
	int i;
	
	web_reg_find("Text=Новое письмо — Яндекс.Почта", 
		LAST);

	/*Correlation comment - Do not change!  Original value='037c6d036c81f75d39d735bfb127b728' Name ='compose_check' Type ='Manual'*/
	web_reg_save_param_attrib(
		"ParamName=compose_check",
		"TagName=input",
		"Extract=value",
		"Name=compose_check",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		LAST);

	/*Correlation comment - Do not change!  Original value='p66rVvHUUE2fdGH/bT/OAReeo84=!kpicuo61' Name ='_ckey' Type ='Manual'*/
	web_reg_save_param_attrib(
		"ParamName=_ckey",
		"TagName=input",
		"Extract=value",
		"Name=_ckey",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		LAST);
	
	
	for(i=0; i<=2; i++) {

		web_url("retpath=",
			"URL=https://mail.yandex.ru/lite/compose/retpath=", 
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=https://mail.yandex.ru/lite", 
			"Snapshot=t420.inf", 
			"Mode=HTML", 
			LAST);
	
		web_submit_data("compose-action.xml",
			"Action=https://mail.yandex.ru/lite/compose-action.xml",
			"Method=POST",
			"EncType=multipart/form-data",
			"TargetFrame=",
			"RecContentType=text/html",
			"Referer=https://mail.yandex.ru/lite/compose/retpath=",
			"Snapshot=t430.inf",
			"Mode=HTML",
			ITEMDATA,
			"Name=request", "Value=", ENDITEM,
			"Name=to", "Value={Send_to}@yandex.ru, ", ENDITEM,
			"Name=cc", "Value=", ENDITEM,
			"Name=bcc", "Value=", ENDITEM,
			"Name=subj", "Value={Header}", ENDITEM,
			"Name=send", "Value={Text}", ENDITEM,
			"Name=att", "Value=", "File=yes", ENDITEM,
			"Name=doit", "Value=Отправить", ENDITEM,
			"Name=compose_check", "Value={compose_check}", ENDITEM,
			"Name=_ckey", "Value={_ckey}", ENDITEM,
			"Name=ttype", "Value=plain", ENDITEM,
			"Name=_handlers", "Value=do-send", ENDITEM,
			"Name=style", "Value=lite", ENDITEM,
			"Name=fid", "Value=", ENDITEM,
			"Name=from_mailbox", "Value={Login_user_name}@yandex.ru", ENDITEM,
			"Name=from_name", "Value=NT_01_user Userov", ENDITEM,
			"Name=mark_as", "Value=", ENDITEM,
			"Name=mark_ids", "Value=", ENDITEM,
			"Name=retpath", "Value=inbox", ENDITEM,
			"Name=nohl", "Value=", ENDITEM,
			LAST);
	}
}