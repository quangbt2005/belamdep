<?php
function P_XML_ErrorCheck_CheckValue($Array, $Value, $Value_Array) {
	if (mb_strtolower($Array["null"]) == "ok") {
		if (strlen($Value) <= 0) {
			return "";
		}
	}

	while (true) {
		if (is_array($Array["date"]) == TRUE) {
			break;
		}
		if (mb_strlen($Array["zip"]) > 0) {
			break;
		}
		if (mb_strlen($Array["tel"]) > 0) {
			break;
		}
		if (mb_strlen($Array["email"]) > 0) {
			break;
		}
		if (mb_strtolower($Array["reverse"]) == "on") {
			break;
		}

		$ERROR = P_XML_ErrorCheck_CheckLength($Value, $Array);

		if (mb_strlen($ERROR) > 0) {
			return $ERROR;
		}

		break;
	}

	/*********************************************** P007 : Change End!! */

	$Type = mb_strtolower($Array["type"]);

	/* P002 : Add Start!! ************************************************/

	if (mb_strlen($Array["regex"]) > 0) {
		$Type = $Array["type"];

		if (mb_strtolower($Array["regex"]) == "match") {
			$RegBool = @ mb_ereg($Type, $Value);

			if ($RegBool == FALSE) {
				return P_XML_ErrorCheck_Get_ErrorMessage($Array, "type");
			}
		} else
			if (mb_strtolower($Array["regex"]) == "match/i") {
				$RegBool = @ mb_eregi($Type, $Value);

				if ($RegBool == FALSE) {
					return P_XML_ErrorCheck_Get_ErrorMessage($Array, "type");
				}
			} else
				if (mb_strtolower($Array["regex"]) == "replace/i") {
					$RegBool = @ mb_eregi_replace($Type, "", $Value);

					if (mb_strlen($RegBool) > 0) {
						return P_XML_ErrorCheck_Get_ErrorMessage($Array, "type");
					}
				} else {
					$RegBool = @ mb_ereg_replace($Type, "", $Value);

					if (mb_strlen($RegBool) > 0) {
						return P_XML_ErrorCheck_Get_ErrorMessage($Array, "type");
					}
				}
		/* P007 : Add Start!! ************************************************/

		if (mb_strtolower($Array["reverse"]) == "on") {
			$ERROR = P_XML_ErrorCheck_CheckLength($Value, $Array);

			if (mb_strlen($ERROR) > 0) {
				return $ERROR;
			}
		}

		/************************************************** P007 : Add End!! */
	} else {

		/************************************************** P002 : Add End!! */

		switch ($Type) {
			case "email" :
			case "web_mail" :
			case "mobile_mail" :
			case "mobile_mail_i" :
			case "mobile_mail_e" :
			case "mobile_mail_j" :
				/* P004 : Add Start!! ************************************************/
			case "email_p2" :
			case "web_mail_p2" :
			case "mobile_mail_p2" :
			case "mobile_mail_i_p2" :
			case "mobile_mail_e_p2" :
			case "mobile_mail_j_p2" :
				/* P005 : Delete Start!! **********************************************
				     case "email_yl" :
				     case "web_mail_yl" :
				     case "mobile_mail_yl" :
				     case "mobile_mail_i_yl" :
				     case "mobile_mail_e_yl" :
				     case "mobile_mail_j_yl" :
				*********************************************** P005 : Delete End!!! */
				/************************************************** P004 : Add End!! */
				{
					$Message = P_XML_ErrorCheck_CheckValueEmail($Array, $Value, $Type);

					if (mb_strlen($Message) > 0) {
						return $Message;
					}

					break;
				}
			case "datetime" :
			case "date" :
			case "time" :
			case "tel" :
			case "zip" :
			case "zip7" :
			case "tel_p" : /* P003 : Add!! */
				/* P006 : Add Start!! ************************************************/
			case "zip_p2" :
			case "zip7_p2" :
			case "tel_p2" :
			case "tel_p2m" :
			case "tel_p2o" :
				/************************************************** P006 : Add End!! */
				{
					$CK_Array = array (
						"datetime" => "P_Check_DateTime",
						"date" => "P_Check_Date",
						"time" => "P_Check_Time",
						"tel" => "P_Check_Telephone",
						"zip" => "P_Check_PostalCode",
						"zip7" => "P_Check_PostalCode7",

						
					);

					$CK_Array["tel_p"] = "P_Check_Telephone_P"; /* P003 : Add!! */
					/* P006 : Add Start!! ************************************************/

					$CK_Array["zip_p2"] = "P_Check_PostalCode_P2";
					$CK_Array["zip7_p2"] = "P_Check_PostalCode7_P2";
					$CK_Array["tel_p2"] = "P_Check_Telephone_P2";
					$CK_Array["tel_p2m"] = "P_Check_Telephone_P2M";
					$CK_Array["tel_p2o"] = "P_Check_Telephone_P2O";

					/************************************************** P006 : Add End!! */

					$Number = $CK_Array[$Type];
					$Bool = $Number ($Value);

					if ($Bool != TRUE) {
						return P_XML_ErrorCheck_Get_ErrorMessage($Array, "type");
					}

					break;
				}
			case "number" :
			case "alpha" :
			case "alpha_number" :
				{
					$CK_Array = array (
						"number" => "1",
						"alpha" => "10",
						"alpha_number" => "19"
					);

					$Number = $CK_Array[$Type];

					if (P_Word_Check_Alpha($Value, $Number) != TRUE) {
						return P_XML_ErrorCheck_Get_ErrorMessage($Array, "type");
					}

					break;
				}
			case "hira_kata_onbiki" :
			case "kata_onbiki" :
			case "hira_onbiki" :
			case "hira_kata" :
			case "kata" :
			case "hira" :
				{
					$CK_Array = array (
						"hira_kata_onbiki" => "6",
						"kata_onbiki" => "5",
						"hira_onbiki" => "4",
						"hira_kata" => "3",
						"kata" => "2",
						"hira" => "1"
					);

					$Number = $CK_Array[$Type];

					if (P_Check_Hira_Kata($Value, $Number) != TRUE) {
						return P_XML_ErrorCheck_Get_ErrorMessage($Array, "type");
					}

					break;
				}
				/* P008 : Add Start!! ************************************************/
			case "hira_kata_ex" :
			case "kata_ex" :
			case "hira_ex" :
			case "hira_kata_onbiki_ex" :
			case "kata_onbiki_ex" :
			case "hira_onbiki_ex" :
				{
					$CK_Array = array (
						"hira_kata_onbiki_ex" => "6",
						"kata_onbiki_ex" => "5",
						"hira_onbiki_ex" => "4",
						"hira_kata_ex" => "3",
						"kata_ex" => "2",
						"hira_ex" => "1"
					);

					$Number = $CK_Array[$Type];

					if (P_Check_Hira_Kata($Value, $Number, "OFF") != TRUE) {
						return P_XML_ErrorCheck_Get_ErrorMessage($Array, "type");
					}

					break;
				}
				/************************************************** P008 : Add End!! */
			case "ascii" :
			case "multibyte" :
				{
					$CK_Array = array (
						"ascii" => "1",
						"multibyte" => "2"
					);

					$Number = $CK_Array[$Type];

					if (P_Check_Ascii_MultiByte($Value, $Number) != TRUE) {
						return P_XML_ErrorCheck_Get_ErrorMessage($Array, "type");
					}

					break;
				}
			default :
				{
					if (mb_strlen($Array["type"]) > 0) {
						if (P_Word_Check_Beta($Value, $Array["type"]) != TRUE) {
							return P_XML_ErrorCheck_Get_ErrorMessage($Array, "type");
						}
					}

					break;
				}
		}

		if (mb_strlen($Array["age"]) > 0) {
			switch (mb_strtolower($Array["type"])) {
				case "date" :
					{
						$WK_Value = sprintf("%d", $Array["age"]);

						if (P_Date_MinorityCheck("", $Value, $WK_Value) != TRUE) {
							return P_XML_ErrorCheck_Get_ErrorMessage($Array, "age");
						}

						break;
					}
				case "number" :
					{
						if ($Value < sprintf("%d", $Array["age"])) {
							return P_XML_ErrorCheck_Get_ErrorMessage($Array, "age");
						}

						break;
					}
				case "datetime" :
					{
						$WK_Value1 = sprintf("%d", substr($Value, 0, 8));
						$WK_Value2 = sprintf("%d", $Array["age"]);

						if (P_Date_MinorityCheck("", $WK_Value1, $WK_Value2) != TRUE) {
							return P_XML_ErrorCheck_Get_ErrorMessage($Array, "age");
						}

						break;
					}
				default :
					{
						break;
					}
			}
		}
		/* P007 : Add Start!! ************************************************/

		if (mb_strtolower($Array["reverse"]) == "on") {
			$ERROR = P_XML_ErrorCheck_CheckLength($Value, $Array);

			if (mb_strlen($ERROR) > 0) {
				return $ERROR;
			}
		}

		/************************************************** P007 : Add End!! */
	} /* P002 : Add!! */

	if (is_array($Array["enum"]) == TRUE) {
		if ($Array["enum"][$Value] != "ON") {
			return P_XML_ErrorCheck_Get_ErrorMessage($Array, "enum");
		}
	}

	/* P007 : Add Start!! ************************************************/

	if (is_array($Array["date"]) == TRUE) {
		$ERROR = P_XML_ErrorCheck_CheckLength($Value, $Array);

		if (mb_strlen($ERROR) > 0) {
			return $ERROR;
		}

		$Date_Array = $Array["date"];

		switch (mb_strtolower($Date_Array["format"])) {
			case "datetime" :
				{
					$Target_Value = date("YmdHis");
					$Target_Date = "datetime";
					$Bool = P_Check_DateTime($Value);
					break;
				}
			case "time" :
				{
					$Target_Value = date("His");
					$Target_Date = "time";
					$Bool = P_Check_Time($Value);
					break;
				}
			default :
				{
					$Target_Value = date("Ymd");
					$Target_Date = "date";
					$Bool = P_Check_Date($Value);
					break;
				}
		}

		if ($Bool != TRUE) {
			return P_XML_ErrorCheck_Get_ErrorMessage($Array, "date", "format");
		}

		if (mb_strlen($Date_Array["compare"]) > 0) {
			$Date_Compare = $Date_Array["compare"];

			$Bool = P_XML_ErrorCheck_CheckDate($Value, $Value_Array[$Date_Compare], $Date_Array["operator"], $Date_Array["skip"], $Target_Date);

			if ($Bool != TRUE) {
				return P_XML_ErrorCheck_Get_ErrorMessage($Array, "date", "compare");
			}
		}

		if (mb_strtolower($Date_Array["now"]) == "on") {
			$Bool = P_XML_ErrorCheck_CheckDate($Value, $Target_Value, $Date_Array["now_operator"], "", $Target_Date);

			if ($Bool != TRUE) {
				return P_XML_ErrorCheck_Get_ErrorMessage($Array, "date", "now");
			}
		}
	}

	if (mb_strlen($Array["zip"]) > 0) {
		$ERROR = P_XML_ErrorCheck_CheckLength($Value, $Array);

		if (mb_strlen($ERROR) > 0) {
			return $ERROR;
		}

		switch (mb_strtolower($Array["zip"])) {
			case "zip7_p2" :
				{
					$Bool = P_Check_PostalCode7_P2($Value);
					break;
				}
			case "zip_p2" :
				{
					$Bool = P_Check_PostalCode_P2($Value);
					break;
				}
			case "zip7" :
				{
					$Bool = P_Check_PostalCode7($Value);
					break;
				}
			default :
				{
					$Bool = P_Check_PostalCode($Value);
					break;
				}
		}

		if ($Bool != TRUE) {
			return P_XML_ErrorCheck_Get_ErrorMessage($Array, "zip");
		}
	}

	if (mb_strlen($Array["tel"]) > 0) {
		$ERROR = P_XML_ErrorCheck_CheckLength($Value, $Array);

		if (mb_strlen($ERROR) > 0) {
			return $ERROR;
		}

		switch (mb_strtolower($Array["tel"])) {
			case "tel_p2m" :
				{
					$Bool = P_Check_Telephone_P2M($Value);
					break;
				}
			case "tel_p2o" :
				{
					$Bool = P_Check_Telephone_P2O($Value);
					break;
				}
			case "tel_p2" :
				{
					$Bool = P_Check_Telephone_P2($Value);
					break;
				}
			case "tel_p" :
				{
					$Bool = P_Check_Telephone_P($Value);
					break;
				}
			default :
				{
					$Bool = P_Check_Telephone($Value);
					break;
				}
		}

		if ($Bool != TRUE) {
			return P_XML_ErrorCheck_Get_ErrorMessage($Array, "tel");
		}
	}

	if (mb_strlen($Array["email"]) > 0) {
		$ERROR = P_XML_ErrorCheck_CheckLength($Value, $Array);

		if (mb_strlen($ERROR) > 0) {
			return $ERROR;
		}

		$ERROR = P_XML_ErrorCheck_CheckValueEmail($Array, $Value, $Type, "email");

		if (mb_strlen($ERROR) > 0) {
			return $ERROR;
		}
	}

	/************************************************** P007 : Add End!! */
	/* P003 : Add Start!! ************************************************/

	if (mb_strlen($Array["match"]) > 0) {
		$F1 = $Array["match"];
		$F2 = $Value_Array[$F1];

		while (true) {
			if (mb_strlen($Array["match_operator"]) > 0) {
				$ERROR = P_XML_ErrorCheck_CheckMatch($Value, $F2, $Array);

				if (mb_strlen($ERROR) > 0) {
					return $ERROR;
				}

				break;
			}

			$F3 = mb_strtolower($Array["bool"]);

			if ($F3 == "false") {
				if (mb_strlen($F2) == mb_strlen($Value) && $F2 == $Value) {
					return P_XML_ErrorCheck_Get_ErrorMessage($Array, "match");
				}
			} else {
				if (!(mb_strlen($F2) == mb_strlen($Value) && $F2 == $Value)) {
					return P_XML_ErrorCheck_Get_ErrorMessage($Array, "match");
				}
			}

			break;
		}

		if (mb_strtolower($Array["gaiji"]) == "ng") {
			$GAIJI = P_SJIS_Convert_Get_DefaultGAIJI();

			global $P_SJIS_SetGAIJI;

			while (mb_strlen($P_SJIS_SetGAIJI) > 0) {
				if (mb_strtoupper($P_SJIS_SetGAIJI) == "DELETE") {
					break;
				}
				if (mb_strtoupper($P_SJIS_SetGAIJI) == "CODE CONVERT") {
					break;
				}

				$GAIJI = $P_SJIS_SetGAIJI;
				break;
			}

			$GAIJI_ICHI = mb_strpos($Value, $GAIJI);

			if (mb_strlen($GAIJI_ICHI) > 0) {
				return P_XML_ErrorCheck_Get_ErrorMessage($Array, "gaiji");
			}
		}

		if (is_array($Array["extension"]) == TRUE) {
			$Funcion_Array = $Array["extension"];

			foreach ($Funcion_Array as $Function) {
				if (mb_strlen($Function) <= 0) {
					continue;
				}

				$Result = $Function ($Value, $Value_Array);

				if (mb_strlen($Result) > 0) {
					return P_XML_ErrorCheck_Get_ErrorMessage($Array, "extension", $Result);
				}
			}
		}

		return "";
	}
}
/*********************************************************************/
function P_XML_ErrorCheck_CheckDate($Date1, $Date2, $Operator, $SKIP_FLG, $Target) {
	$Bool = TRUE;

	if (mb_strtoupper($SKIP_FLG) == "ON") {
		if (mb_strlen($Date1) <= 0 || mb_strlen($Date2) <= 0) {
			return $Bool;
		}
	} else {
		if (mb_strlen($Date1) <= 0 || mb_strlen($Date2) <= 0) {
			$Bool = FALSE;
			return $Bool;
		}
	}

	switch (mb_strtolower($Target)) {
		case "datetime" :
			{
				if (P_Check_DateTime($Date1) != TRUE) {
					return $Bool;
				}
				if (P_Check_DateTime($Date2) != TRUE) {
					return $Bool;
				}
				break;
			}
		case "time" :
			{
				if (P_Check_Time($Date1) != TRUE) {
					return $Bool;
				}
				if (P_Check_Time($Date2) != TRUE) {
					return $Bool;
				}
				break;
			}
		default :
			{
				if (P_Check_Date($Date1) != TRUE) {
					return $Bool;
				}
				if (P_Check_Date($Date2) != TRUE) {
					return $Bool;
				}
				break;
			}
	}

	switch (mb_strtolower($Operator)) {
		case "8" :
			{
				if ($Date1 >= $Date2) {
					return $Bool;
				}
				break;
			}
		case "7" :
			{
				if ($Date1 > $Date2) {
					return $Bool;
				}
				break;
			}
		case "6" :
			{
				if ($Date1 <= $Date2) {
					return $Bool;
				}
				break;
			}
		case "5" :
			{
				if ($Date1 < $Date2) {
					return $Bool;
				}
				break;
			}
		case "4" :
			{
				if ($Date1 !== $Date2) {
					return $Bool;
				}
				break;
			}
		case "3" :
			{
				if ($Date1 === $Date2) {
					return $Bool;
				}
				break;
			}
		case "2" :
			{
				if (!(mb_strlen($Date1) == mb_strlen($Date2) && $Date1 == $Date2)) {
					return $Bool;
				}
				break;
			}
		default :
			{
				if (mb_strlen($Date1) == mb_strlen($Date2) && $Date1 == $Date2) {
					return $Bool;
				}

				break;
			}
	}

	$Bool = FALSE;

	return $Bool;
}

/*********************************************************************/
function P_XML_ErrorCheck_CheckMatch($Value1, $Value2, $Array) {
	$Bool = "";

	if (mb_strtoupper($Array["match_skip"]) == "ON") {
		if (mb_strlen($Value1) <= 0 || mb_strlen($Value2) <= 0) {
			return $Bool;
		}
	} else {
		if (mb_strlen($Value1) <= 0 || mb_strlen($Value2) <= 0) {
			return P_XML_ErrorCheck_Get_ErrorMessage($Array, "match");
		}
	}

	switch ($Array["match_operator"]) {
		case "8" :
			{
				if ($Value1 >= $Value2) {
					return $Bool;
				}
				break;
			}
		case "7" :
			{
				if ($Value1 > $Value2) {
					return $Bool;
				}
				break;
			}
		case "6" :
			{
				if ($Value1 <= $Value2) {
					return $Bool;
				}
				break;
			}
		case "5" :
			{
				if ($Value1 < $Value2) {
					return $Bool;
				}
				break;
			}
		case "4" :
			{
				if ($Value1 !== $Value2) {
					return $Bool;
				}
				break;
			}
		case "3" :
			{
				if ($Value1 === $Value2) {
					return $Bool;
				}
				break;
			}
		case "2" :
			{
				if (!(mb_strlen($Value1) == mb_strlen($Value2) && $Value1 == $Value2)) {
					return $Bool;
				}
				break;
			}
		default :
			{
				if (mb_strlen($Value1) == mb_strlen($Value2) && $Value1 == $Value2) {
					return $Bool;
				}

				break;
			}
	}

	return P_XML_ErrorCheck_Get_ErrorMessage($Array, "match");
}

/*********************************************************************/
function P_XML_ErrorCheck_CheckLength($Value, $Array) {
	if (mb_strtolower($Array["null"]) == "ok") {
		if (strlen($Value) <= 0) {
			return "";
		}
	}

	if (strlen($Value) <= 0) {
		return P_XML_ErrorCheck_Get_ErrorMessage($Array, "null");
	}

	if (mb_strtolower($Array["fixed"]) == "on") {
		if (mb_strtolower($Array["multibyte"]) == "on") {
			if (mb_strlen($Value) != sprintf("%d", $Array["length"])) {
				return P_XML_ErrorCheck_Get_ErrorMessage($Array, "length");
			}
		} else {
			if (strlen($Value) != sprintf("%d", $Array["length"])) {
				return P_XML_ErrorCheck_Get_ErrorMessage($Array, "length");
			}
		}
	}

	if (sprintf("%d", $Array["min"]) > 0) {
		if (sprintf("%d", $Array["min"]) > sprintf("%d", $Array["length"])) {
			$Min = sprintf("%d", $Array["length"]);
			$Max = sprintf("%d", $Array["min"]);
		} else {
			$Min = sprintf("%d", $Array["min"]);
			$Max = sprintf("%d", $Array["length"]);
		}

		if (mb_strtolower($Array["multibyte"]) == "on") {
			if (!(mb_strlen($Value) <= $Max && mb_strlen($Value) >= $Min)) {
				return P_XML_ErrorCheck_Get_ErrorMessage($Array, "length");
			}
		} else {
			if (!(strlen($Value) <= $Max && strlen($Value) >= $Min)) {
				return P_XML_ErrorCheck_Get_ErrorMessage($Array, "length");
			}
		}
	} else {
		if (mb_strtolower($Array["multibyte"]) == "on") {
			if (mb_strlen($Value) > sprintf("%d", $Array["length"])) {
				return P_XML_ErrorCheck_Get_ErrorMessage($Array, "length");
			}
		} else {
			if (strlen($Value) > sprintf("%d", $Array["length"])) {
				return P_XML_ErrorCheck_Get_ErrorMessage($Array, "length");
			}
		}
	}

	return "";
}

switch (mb_strtoupper(mb_internal_encoding())) {
	case "SJIS" :
	case "SJIS-WIN" :
		{
			@ include_once (LIB_PATH . "P_SJIS/P_SJIS_Convert_Get_DefaultGAIJI_SJIS_Private_Function.inc");
			break;
		}
	case "UTF8" :
	case "UTF-8" :
		{
			@ include_once (LIB_PATH . "P_SJIS/P_SJIS_Convert_Get_DefaultGAIJI_UTF8_Private_Function.inc");
			break;
		}
	default :
		{
			@ include_once (LIB_PATH . "P_SJIS/P_SJIS_Convert_Get_DefaultGAIJI_EUC_Private_Function.inc");
			break;
		}
}
?>
