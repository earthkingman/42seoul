
CREATE DATABASE IF NOT EXISTS wordpress;
CREATE USER IF NOT EXISTS 'parkjiyul'@'localhost' IDENTIFIED BY '1234';
GRANT ALL PRIVILEGES ON wordpress.* TO 'parkjiyul'@'localhost' WITH GRANT OPTION;