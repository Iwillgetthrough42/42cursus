FROM debian:buster
RUN apt-get update
RUN apt-get -y install php7.3 php-mysqli php-fpm mariadb-client curl
COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/
ADD https://wordpress.org/wordpress-5.9.3.tar.gz /var/www/
RUN cd /var/www && tar -xzvf wordpress-5.9.3.tar.gz
RUN rm -f /var/www/wordpress-5.9.3.tar.gz
RUN rm -f /var/www/wordpress/wp-config-sample.php
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp
COPY ./conf/wp-config.php .
COPY ./tools/script.sh .
ENTRYPOINT ["bash", "script.sh"]
CMD ./usr/sbin/php-fpm7.3 -F
