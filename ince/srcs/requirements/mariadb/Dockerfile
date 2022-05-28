From debian:buster
RUN apt-get update
RUN apt-get install mariadb-server -y
COPY ./50-server.cnf /etc/mysql/mariadb.conf.d/
COPY ./install.sql .
RUN service mysql start && mysql < install.sql
RUN rm -f install.sql
CMD ["mysqld"]

