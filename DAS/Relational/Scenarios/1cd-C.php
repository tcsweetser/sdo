<?php
/* 
+----------------------------------------------------------------------+
| (c) Copyright IBM Corporation 2005.                                  |
| All Rights Reserved.                                                 |
+----------------------------------------------------------------------+
|                                                                      |
| Licensed under the Apache License, Version 2.0 (the "License"); you  |
| may not use this file except in compliance with the License. You may |
| obtain a copy of the License at                                      |
| http://www.apache.org/licenses/LICENSE-2.0                           |
|                                                                      |
| Unless required by applicable law or agreed to in writing, software  |
| distributed under the License is distributed on an "AS IS" BASIS,    |
| WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or      |
| implied. See the License for the specific language governing         |
| permissions and limitations under the License.                       |
+----------------------------------------------------------------------+
| Author: Matthew Peters                                               |
+----------------------------------------------------------------------+

*/

require_once 'SDO/DAS/Relational.php';
require_once 'company_metadata.inc.php';

/**
 * Scenario - Create one company and one department 
 *
 */

/*************************************************************************************
 * Empty out the two tables
 *************************************************************************************/
$dbh = new PDO("mysql:dbname=COMPANYDB;host=localhost",DATABASE_USER,DATABASE_PASSWORD);
$pdo_stmt = $dbh->prepare('DELETE FROM COMPANY;');
$rows_affected = $pdo_stmt->execute();
$pdo_stmt = $dbh->prepare('DELETE FROM DEPARTMENT;');
$rows_affected = $pdo_stmt->execute();


/**************************************************************
 * GET AND INITIALISE A DAS WITH THE METADATA
 ***************************************************************/
try {
    $das = new SDO_DAS_Relational ($database_metadata,'company',$SDO_reference_metadata);
} catch (SDO_DAS_Relational_Exception $e) {
    echo "SDO_DAS_Relational_Exception raised when trying to create the DAS.";
    echo "Probably something wrong with the metadata.";
    echo "\n".$e->getMessage();
    exit();
}

/**************************************************************
 * CREATE A COMPANY OBJECT AND SET ITS NAME
 ***************************************************************/

$root = $das -> createRootDataObject();
$acme = $root -> createDataObject('company');
$acme -> name = "Acme";
//$acme->id = 1;

$shoe = $acme->createDataObject('department');
$shoe->name = 'Shoe';

/**************************************************************
 * GET A DATABASE CONNECTION
 ***************************************************************/
$dbh = new PDO("mysql:dbname=COMPANYDB;host=localhost",DATABASE_USER,DATABASE_PASSWORD);

/**************************************************************
 * WRITE THE CHANGES OUT
 ***************************************************************/
try {
    $das -> applyChanges($dbh, $root);
    echo "\nCompany Acme has been written to the database\n";

} catch (SDO_DAS_Relational_Exception $e) {
    echo "\nSDO_DAS_Relational_Exceptionraised when trying to apply changes.";
    echo "\nProbably something wrong with the data graph.";
    echo "\n".$e->getMessage();
    exit();
}


?>