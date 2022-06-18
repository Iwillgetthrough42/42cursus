all:
	mkdir -p /home/$(USER)/data/mariadb
	mkdir -p  /home/$(USER)/data/wordpress
	cd srcs && docker-compose -f docker-compose.yml up -d --build
clean:
	cd srcs && docker-compose -f docker-compose.yml down

fclean: clean
	sudo rm -rf /home/$(USER)/data/mariadb
	sudo rm -rf /home/$(USER)/data/wordpress
	docker system prune -a

re:	fclean all

.PHONY: all fclean clean re
