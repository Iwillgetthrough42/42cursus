From debian:buster
RUN apt-get update
RUN apt-get install mariadb-server -y
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/
COPY ./conf/install.sql .
COPY ./tools/script.sh .
ENTRYPOINT ["bash", "script.sh"]
CMD ["mysqld"]
