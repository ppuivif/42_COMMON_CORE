all: up

up:
	@docker compose up --build -d

down:
	@docker compose down

clean:
	@docker compose down -v --remove-orphans
	@docker system prune -f --volumes

re: clean all
