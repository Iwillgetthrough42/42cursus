if [ -f "wp-config.php" ]; then
    sed -i "s/MYSQL_DATABASE/$MYSQL_DATABASE/g" wp-config.php
    sed -i "s/MYSQL_USER/$MYSQL_USER/g" wp-config.php
    sed -i "s/MYSQL_PASSWORD/$MYSQL_PASSWORD/g" wp-config.php
    mv wp-config.php /var/www/wordpress/
fi

mkdir -p /run/php

exec "$@"
