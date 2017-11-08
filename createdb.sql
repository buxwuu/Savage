drop database if exists prasanna;
create database prasanna;
use prasanna;

create table if not exists player_info (
	player_ID int(4) not null,	
	username char(20) not null,
	age int(2) not null,
	gender char(1) not null,
	primary key (player_ID)
);

insert into player_info (username, player_ID, age, gender) values
	('user1', 1, 25, 'M'), 
	('user2', 2, 16, 'F'),
	('user3', 3, 35, 'F'),
	('user4', 4, 20, 'M');

create table if not exists inventory (
	player_ID char(20) not null,
	crystal_skull int not null,
	rope int not null,
	coconut int not null,
	wood int not null,
	granite int not null,
	axe int not null,
	hammer int not null,
	glasses int not null,
	magnifying_glass int not null,
	ore int not null,
	nails int not null,
	gold int not null,
	diamonds int not null,
	medicine int not null,
	primary key (player_ID)
);

insert into inventory (player_ID, crystal_skull, rope, coconut, wood, granite, axe, hammer, glasses, magnifying_glass, ore, nails, gold, diamonds, medicine)
values
('user1', 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0),
('user2', 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1),
('user3', 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0),
('user4', 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1);
