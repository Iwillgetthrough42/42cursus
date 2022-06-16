wp core config --dbname=${MYSQL_DATABASE} --dbuser=${MYSQL_USER} --dbpass=${MYSQL_PASSWORD} --dbhost=mariadb --dbprefix=wp_ --allow-root --path=/var/www/wordpress/
wp core install --url=${DOMAIN_NAME} --title="wordpress" --admin_user=${MYSQL_USER} --admin_password=${MYSQL_PASSWORD} --admin_email=${EMAIL} --allow-root --path=/var/www/wordpress/


mkdir -p /run/php

exec "$@"
