var app=angular.module("app", []);
	app.controller("wish",function($scope){
	var hour = new Date().getHours();
	if(hour>=0 && hour<12){
	$scope.greeting = "Good Morning!";}
	else if (hour>=12 && hour<18){
	$scope.greeting = "Good Afternoon!";}
	else {$scope.greeting = "Good Evening!";}	
});

    app.controller("ksk", function($scope) {
	$scope.job1 = "Wipro Technologies - (May 2008 - July 2014)";
	$scope.job2 = "Old Dominion University - (Jan 2015 - May 2016)";
	$scope.desc = "Software Engineer";    
	$scope.descr1 = "Student Developer - Information Technology Services - (May 2015 - May 2016)";
	$scope.descr2 = "Graduate Teaching Assistant - Department of Computer Science - (Jan 2015 - May 2015)";
	$scope.subj1 = "Database Concepts";
	$scope.subj2 = "Advanced Data Structures and Algorithms";
	$scope.desc1 = ["Worked with Cramer application that is used as Network inventory tool. Fixed bugs and used Cramer to build SDH, LDH and OLO network circuits using Java.","Wrote automated test scripts in selenium web driver using Core Java for UK client and tested webpage using Xpath in different browsers. Used SQL queries to test the database in the backend.", "Lead a team of 4 people in performing data cleansing using SQL queries in the database and acted as Quality Auditor for the project.","Used test management tool, HP Quality center for tracking defects to closure.", "Automated the excel daily reports that displays the data automatically of the individual team members which reduced the daily manual work of updating the records."];
	$scope.desc2 = ["Developed a web application for the Old Dominion University using PHP, angular JS, bootstrap, material design.","Retrieved details of multiple users from different XML files using XSLT transformations in PHP.","Implemented test cases using selenium web driver to test Old Dominion website.","Worked with VIVO application and Karma tool to convert the data into RDF which is compatible with VIVO application."];
	$scope.desc3 = ["Prepared assignments in Relational Algebra, SQL, PL/SQL.", "Assisted in designing projects that expects students to create database, ER diagrams and writing SQL queries to retrieve data.", "Graded the homeworks that involved the concepts of relational database"];
    $scope.desc4 = ["Conducted weekly sessions to help students with their questions in the coursework", "Graded programming assignments and project written in C++", "Maintained course website and assisted in creating the homework assignments."];
	$scope.subj3 = "Wipro Technologies";
	$scope.subj4 = "Loyola Academy";
	$scope.desc5 = "College Second Topper";
	$scope.desc6 = ["Thanks a Zillion - awarded twice","Feather in My Cap - awarded once"];
});

app.controller("ed",function($scope){
    $scope.clg1 = "Loyola Academy - Masters in Physics (specialization in Electronics and Instrumentation) (Grade 3.92)";
    $scope.clg2 = "Old Dominion University - Masters in Computer Science (Grade 3.70)";
	$scope.clg3 = "Sri Sathya Sai University - Bachelor of Science (Honors degree) (Grade 3.96)";
	$scope.list = ["Database Concepts","Introduction to Networks and Communications","Computer Architecture","Algorithms and Data Structures","Information Assurance","Design of Network protocols","Data Mining and Security","Introduction to Bioinformatics","Advanced Systems Programming","Introduction to Parallel Computing","Information Visualization"];
});

app.controller("proj",function($scope){
    $scope.proj1 = "Introduction to Bioinformatics - Extraction of Beta-Strands from protein structures";
	$scope.t1 = "C++, Chimera";
	$scope.desc1 = ["This project aims at hands-on experience with protein structures.","Considered the protein structure from the protein data bank site and extracting the Beta Strand from the input protein structure file.","To understand the definition of a 3-dimensional protein structure and manipulating the protein structure.","Extracted the position and the alignment of a beta strand."];
	$scope.proj2 = "Information Visualization - Analysis of Old Dominion University fee structure";
	$scope.t2 = "HTML, CSS Bootstrap, D3.js, plotly";
	$scope.desc2 = ["The project aims at analysing the structure of fee that each student pays for their coursework.","Understood where Old Dominion University stands with respect to tuition among the universities in Virginia.","The visualizations include information about the tuition and mandatory fee.","Mandatory fee is furthered divided into different categories like transportation, sports etc...that every student may not utilise","Studied the trend of the tuition and mandatory fee over the years."];
	$scope.proj3 = "Data Mining and Security - Profiling for Authentication and Authorization";
	$scope.t3 = "WEKA-data mining tool, Microsoft Excel";
	$scope.desc3 = ["This project involved analyzing data and deriving useful user patterns based on the provided user information for the project.","A dataset was provided and it contained user login and access data for all several users in a particular Department.","A profile had to be developed for each user based on login pattern, session time patterns and access patterns."];
	$scope.proj4 = "Introduction to Parallel Computing - Parallel Quicksort sorted in 60 seconds";
	$scope.t4 = "C++, Spark cluster consisting of  16 nodes, each equipped with 12 CPU cores and 64 GB of RAM";
	$scope.desc4 = ["The aim of the project is to write fast multithreaded code and the task to be accomplished was to implement parallel Quicksort on the Spark compute node using Pthreads.","The input data for this project is an array of 3 Billion 8-byte doubles, target time to sort these numbers is within 60 seconds.","Other set of input data is an array of 6 Billion 4-byte ints, target time to sort the numbers must be below 90 seconds."];
	$scope.proj5 = "Introduction to Parallel Computing -  Comparing three variations of the broadcast operation using MPI";
	$scope.t5 = "C++, MPI library";
	$scope.desc5 = ["The project aims at using the Message Passing Interface (MPI) for comparing three variations of broadcast operation","The ring algorithm using point-to-point communication where  process 0 sends the message to 1, then 1 sends it to 2, then 2 sends it to 3, and so on","The star algorithm using point-to-point communication: process 0 sends the message to 1, then 0 sends it to 2, then 0 sends it to 3, and so on.","The collective broadcast operation provided by the MPI"];
	$scope.proj6 = "Information Assurance -  Enhancing security of information within an organization";
	$scope.t6 = "ITIL (Information Technology Infrastructure Library), Microsoft powerpoint";
	$scope.desc6 = ["The goal of the project is to implement various information assurance concepts learnt in the course in a specific scenario in the organisation","To study the Threats, Vulnerabilities and Risks involved","Security and Privacy Regulations to be designed in the organisation.","Types of Intrusion Detection Systems and Intrusion Prevention Systems to be implemented and understanding the structure of the organisation before implementation."];
	
	});