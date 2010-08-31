<?php
/**************************************************************************************************/
/* Created on May 30, 2010                                                                        */
/**************************************************************************************************/
function IsExistedCustomer($email='')
{
  if(empty($email)) return TRUE;

  $query = 'SELECT COUNT(1) FROM ' . TBL_CUSTOMERS .
           " WHERE customers_email_address='" . P_SQL_Quote($email) . "'";

  $Result = P_MySQL_Real_SELECT( $query ) ;

  return (int)$Result[0] > 0;
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
function CustomerLogin($email, $password)
{
  if(empty($email) || empty($password)) return FALSE;

  $query = 'SELECT customers_id, customers_lastname, customers_password, customers_email_address'
           . ' FROM ' . TBL_CUSTOMERS . " WHERE customers_email_address = '"
           . P_SQL_Quote($email) . "' LIMIT 1";

  $Result = P_MySQL_Real_SELECT_GetArrayIndex($query);
  if(empty($Result[0])) return FALSE;

  $db_password = $Result[0]['customers_password'];
  $stack = explode(':', $db_password);

  if (sizeof($stack) != 2) return FALSE;
  if (md5($stack[1] . $password) == $stack[0]){
    return $Result[0];
  }
  return FALSE;
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
function LoadCustomerById($customer_id)
{
  if(empty($customer_id)) return NULL;

  $query = 'SELECT c.customers_id,customers_firstname,customers_lastname,customers_email_address,'
           . 'customers_telephone,DATE_FORMAT(customers_dob,"%d/%m/%Y") as dob,'
           . 'entry_street_address,customers_gender,entry_state'
           . ' FROM ' . TBL_CUSTOMERS . " c LEFT JOIN " . TBL_ADDRESS . " a ON("
           . 'a.customers_id=c.customers_id) WHERE c.customers_id='
           . P_SQL_Quote_NumberOnly($customer_id) . " LIMIT 1";

  $Result = P_MySQL_Real_SELECT_GetArrayIndex($query);
  if( empty( $Result[0] ) == FALSE ) {
    return $Result[0];
  }

  return NULL;
}
// ---------------------------------------------------------------------------------------------- //
//
// ---------------------------------------------------------------------------------------------- //
function LoadCustomerPasswordById($customer_id)
{
  if(empty($customer_id)) return NULL;

  $query = 'SELECT c.customers_password FROM ' . TBL_CUSTOMERS . " c "
           . 'WHERE c.customers_id='
           . P_SQL_Quote_NumberOnly($customer_id) . " LIMIT 1";

  $Result = P_MySQL_Real_SELECT($query);

  if( empty( $Result[0] ) == FALSE ) {
    return $Result[0];
  }

  return NULL;
}
?>
