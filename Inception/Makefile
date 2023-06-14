all: run

run:
	@echo "Building files for volumes ...\n"
	@sudo mkdir -p /home/joberle/data/wordpress
	@sudo mkdir -p /home/joberle/data/mariadb
	@echo "Building containers ... \n"
	@docker-compose -f ./srcs/docker-compose.yml up -d --build

up:
	@echo "Building containers ... \n"
	@docker-compose -f ./srcs/docker-compose.yml up -d --build

down:
	@echo "Stop containers ... \n"
	@docker-compose -f ./srcs/docker-compose.yml down

clean: down
	@docker rmi -f $$(docker images -qa);
	@docker volume rm $$(docker volume ls -q);
	@sudo rm -rf /home/joberle/data

.PHONY: all up down clean run%
