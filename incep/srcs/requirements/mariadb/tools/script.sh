#!/bin/bash	

sed -i "s/MYSQL_DATABASE/$MYSQL_DATABASE/g" install.sql
sed -i "s/MYSQL_USER/$MYSQL_USER/g" install.sql
sed -i "s/MYSQL_PASSWORD/$MYSQL_PASSWORD/g" install.sql
sed -i "s/MYSQL_SUPER_USER/$MYSQL_SUPER_USER/g" install.sql
sed -i "s/MYSQL_SUPER_PASSWORD/$MYSQL_SUPER_PASSWORD/g" install.sql


service mysql start
mysql < install.sql
service mysql stop

exec "$@"
