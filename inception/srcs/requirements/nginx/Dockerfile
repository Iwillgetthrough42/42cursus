From debian:buster

RUN apt-get update

RUN apt-get upgrade -y

RUN apt-get -y install nginx

RUN apt-get  install openssl -y

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx.key -out /etc/ssl/certs/nginx.crt -subj "/C=AM/ST=Yerevan/L=Yerevan/O=Tumo/OU=42Yerevan/CN=arastepa"

COPY ./default /etc/nginx/sites-enabled/default

CMD ["nginx", "-g", "daemon off;"]
