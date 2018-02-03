<?php

function dir_exists($path_dir)
{
    return is_dir((string) $path_dir);
}

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

function get_dir_root()
{
    if (defined('PATH_DIR_ROOT')) {
        return PATH_DIR_ROOT;
    }

    return set_dir_root() ? PATH_DIR_ROOT : false;
}

function get_dir_template()
{
    if (defined('PATH_DIR_TEMPLATE')) {
        return PATH_DIR_TEMPLATE;
    }

    return 'NOT DEFINED';
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

function set_env_as_utf8_ja($timezone = 'Asia/Tokyo')
{
    if (! function_exists('mb_language')) {
        die('This application requires mb_language.');
    }

    date_default_timezone_set($timezone);
    setlocale(LC_ALL, 'ja_JP');
    mb_language('ja');
    mb_internal_encoding('UTF-8');
    mb_http_output('UTF-8');
    ob_start("mb_output_handler");
}

function set_dir_template($name_dir = '')
{
    if (defined('PATH_DIR_TEMPLATE')) {
        return PATH_DIR_TEMPLATE;
    } elseif (! isset($name_dir)) {
        return false;
    }
    $path = get_dir_root() . $name_dir . DIRECTORY_SEPARATOR;

    return define('PATH_DIR_TEMPLATE', $path);
}

function set_dir_root()
{
    if (defined('PATH_DIR_ROOT')) {
        return PATH_DIR_ROOT;
    }

    $dir_root = dirname(__FILE__) . DIRECTORY_SEPARATOR;

    return define('PATH_DIR_ROOT', $dir_root);
}
