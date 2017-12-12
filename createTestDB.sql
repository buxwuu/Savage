drop database if exists techtest;
create database techtest;
use techtest;

create table if not exists player_info (
	player_ID int primary key auto_increment,	
	username char(20) not null,
	password char(20) not null,
	progress int not null default 0,
        luke bool not null default 0,
        obiwan bool not null default 0
);

create table if not exists inventory (
	player_ID int primary key auto_increment,
	blaster bool not null default 0,
	lightsaber bool not null default 0,
	grenade bool not null default 0,
);