-- Create Schema called "User_info" in mySQL

-- Create the Table
CREATE TABLE Users(
user_ID		int		AUTO_INCREMENT PRIMARY KEY,
first_name		varchar(50),
last_name		varchar(50),
email_address	varchar(50)		UNIQUE,
phone_number	varchar(50)		UNIQUE,
date_of_birth	date,
gender			varchar(50),
country			varchar(50),
user_password	varchar(50)
);

-- Insert example values
INSERT INTO Users(first_name, last_name, email_address, phone_number, date_of_birth, gender, country, user_password)
VALUES
('John', 'Smith', 'john.smith@email.com', '(555) 123-4567', DATE '1995-04-12', 'Male', 'USA', 'JSmith@2026!'),
('Sarah', 'Johnson', 'sarah.johnson@email.com', '(555) 234-5678', DATE '1998-09-21', 'Female', 'Canada', 'SJohnson#98!'),
('Michael', 'Brown', 'michael.brown@email.com', '(555) 345-6789', DATE '1990-12-05', 'Male', 'UK', 'MBrown$1990'),
('Emily', 'Davis', 'emily.davis@email.com', '(555) 456-7890', DATE '2000-07-18', 'Female', 'Australia', 'EmilyD!2000'),
('Alex', 'Wilson', 'alex.wilson@email.com', '(555) 567-8901', DATE '1993-11-30', 'Male', 'USA', 'AlexW#9311')
;
