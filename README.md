# Practice of PHP Built-in Web Server as Phar



## Requirement

- PHP >= 5.4.0
- box.phar
    - Download and install from the [official site](https://box-project.github.io/box2/) or run `$ php ./box_installer.php` to do it for you and make sure to `chmod` 'box_installer.php' to `0755` before install.
    - `$ sudo chmod 0755 ./box_installer.php && php ./box_installer.php`

## How to build

Run below and you'll get the app in './src/' directory compiled/archived as './WebServer.phar'.

```
$ ./box.phar build -c ./box.json
```

## How to run the server('WebServer.phar')

```
php -S localhost:8000 ./WebServer.phar
```

## FAQ 'RuntimeException'

If you get an error below, you need to commit something or tag the current branch with git. This error is caused because in 'box.json' it requests `box.phar` to fetch git information in order to replace the string to display version/build info.

```
[RuntimeException]                                                        
  The tag or commit hash could not be retrieved from ".": fatal: No names   
  found, cannot describe anything.   
```           