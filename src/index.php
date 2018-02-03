<?php
error_reporting(E_ALL ^ E_NOTICE);
include_once('constants.php.inc');
include_once('functions.php.inc');

//echo_hello();

if(set_dir_template('template')){
    $path_file_tpl_index =  get_dir_template() . 'index.tpl';   
    if( file_exists($path_file_tpl_index) ){
        header("Content-Type: text/html; charset=UTF-8");
        include($path_file_tpl_index);
    }
}

