drop database if exists techtest;
create database techtest;
use techtest;

create table if not exists player_info (
	player_ID int primary key auto_increment,	
	username char(20) not null,
	password char(20) not null,
	progress int not null default 0,
    luke int not null default 0,
    obiwan int not null default 0
);

create table if not exists inventory (
	player_ID int,
	blaster int not null default 0,
	lightsaber int not null default 0,
	grenade int not null default 0,
	foreign key (player_ID) references player_info(player_ID)
);