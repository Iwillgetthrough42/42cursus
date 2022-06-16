if [ -f "wp-config.php" ]; then
    sed -i "s/MYSQL_DATABASE/$MYSQL_DATABASE/g" wp-config.php
    sed -i "s/MYSQL_USER/$MYSQL_USER/g" wp-config.php
    sed -i "s/MYSQL_PASSWORD/$MYSQL_PASSWORD/g" wp-config.php
    mv wp-config.php /var/www/wordpress/
    wp core install --url=${DOMAIN_NAME} --title="wordpress" --admin_user=${MYSQL_USER} --admin_password=${MYSQL_PASSWORD} --admin_email=${EMAIL} --allow-root --path=/var/www/wordpress/
fi

mkdir -p /run/php

exec "$@"
