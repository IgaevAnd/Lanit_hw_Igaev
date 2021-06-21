authorization_func(){
	
	/*Correlation comment - Do not change!  Original value='7e688aeca44f8c9d3f521f214ca3aac32e' Name ='track_id' Type ='Manual'*/
	web_reg_save_param_json(
		"ParamName=track_id",
		"QueryString=$.track_id",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/start*",
		LAST);

	web_submit_data("start",
		"Action=https://passport.yandex.ru/registration-validations/auth/multi_step/start",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=application/json",
		"Referer=https://passport.yandex.ru/auth?mode=auth&retpath=http%3A%2F%2Fmail.yandex.ru%2Flite",
		"Snapshot=t372.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=csrf_token", "Value={csrf_token}", ENDITEM,
		"Name=login", "Value={User_name}", ENDITEM,
		"Name=process_uuid", "Value={process_uuid}", ENDITEM,
		"Name=retpath", "Value=http://mail.yandex.ru/lite", ENDITEM,
		LAST);

	web_submit_data("commit_password",
		"Action=https://passport.yandex.ru/registration-validations/auth/multi_step/commit_password",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=application/json",
		"Referer=https://passport.yandex.ru/auth/welcome?mode=auth&retpath=http%3A%2F%2Fmail.yandex.ru%2Flite",
		"Snapshot=t381.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=csrf_token", "Value={csrf_token}", ENDITEM,
		"Name=track_id", "Value={track_id}", ENDITEM,
		"Name=password", "Value={User_password}", ENDITEM,
		"Name=retpath", "Value=http://mail.yandex.ru/lite", ENDITEM,
		LAST);
		
}