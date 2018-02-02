<?php
/* ---------------------------------------------------------------[E] */

function echo_hello()
{
    echo 'Hello World!' . PHP_EOL;
}

/* ---------------------------------------------------------------[G] */

function get_height_console()
{
    $default_width = 30; //デフォルト幅

    if (! is_cli()) {
        return 'n/a';
    }
    $width = trim(`tput lines`); //バッククォートであることに注意

    return is_numeric($width) ? $width : $default_width;
}

function get_root_dir()
{
    return set_root_dir();
}

function get_width_console()
{
    $default_width = 70; //デフォルト幅

    if (! is_cli()) {
        return 'n/a';
    }
    $width = trim(`tput cols`); //バッククォートであることに注意

    return is_numeric($width) ? $width : $default_width;
}

/* ---------------------------------------------------------------[I] */

function is_cli()
{
    return PHP_SAPI === 'cli' || empty($_SERVER['REMOTE_ADDR']);
}

function is_phar()
{
    return strlen(Phar::running()) > 0 ? true : false;
}

/* ---------------------------------------------------------------[S] */

function set_root_dir()
{
    if (defined('DIR_ROOT_SCRIPT')) {
        return DIR_ROOT_SCRIPT;
    } else {
        $dir_root = dirname(__FILE__) . DIRECTORY_SEPARATOR;
        define('DIR_ROOT_SCRIPT', $dir_root);

        return DIR_ROOT_SCRIPT;
    }
}


