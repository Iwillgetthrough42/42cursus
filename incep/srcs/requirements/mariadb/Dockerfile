From debian:buster
RUN apt-get update
RUN apt-get install mariadb-server -y
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/
COPY ./tools/install.sql .
COPY ./tools/script.sh .
ARG MYSQL_DATABASE
ARG MYSQL_USER
ARG MYSQL_PASSWORD
ARG MYSQL_SUPER_USER
ARG MYSQL_SUPER_PASSWORD
ENV MYSQL_DATABASE=${MYSQL_DATABASE}
ENV MYSQL_USER=${MYSQL_USER}
ENV MYSQL_PASSWORD=${MYSQL_PASSWORD}
ENV MYSQL_SUPER_USER=${MYSQL_SUPER_USER}
ENV MYSQL_SUPER_PASSWORD=${MYSQL_SUPER_PASSWORD}
RUN sh script.sh
RUN service mysql start && mysql < install.sql
CMD ["mysqld"]
