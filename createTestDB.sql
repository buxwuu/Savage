drop database if exists techtest;
create database techtest;
use techtest;

create table if not exists player_info (
	player_ID int primary key auto_increment,	
	username char(20) not null,
	password char(20) not null,
	progress int not null default 0
);

create table if not exists inventory (
	player_ID char(20) not null default 0,
	blaster bool not null default 0,
	lightsaber bool not null default 0,
	grappling_hook bool not null default 0,
	primary key (player_ID)
);