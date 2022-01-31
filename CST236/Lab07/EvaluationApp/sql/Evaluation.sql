SET  ARITHABORT, CONCAT_NULL_YIELDS_NULL, ANSI_NULLS, ANSI_PADDING, ANSI_WARNINGS, QUOTED_IDENTIFIER ON 
SET  NUMERIC_ROUNDABORT OFF
GO

USE [master]

GO


IF  (   DB_ID(N'Evaluation') IS NOT NULL
    AND DATABASEPROPERTYEX(N'Evaluation','Status') <> N'ONLINE')
BEGIN
    RAISERROR(N'The state of the target database, %s, is not set to ONLINE. To deploy to this database, its state must be set to ONLINE.', 16, 127,N'Evaluation') WITH NOWAIT
    RETURN
END
GO

     
IF (DB_ID(N'Evaluation') IS NOT NULL) 
BEGIN
    ALTER DATABASE [Evaluation]
    SET SINGLE_USER WITH ROLLBACK IMMEDIATE;
    DROP DATABASE [Evaluation];
END
GO
CREATE DATABASE [Evaluation] COLLATE SQL_Latin1_General_CP1_CS_AS;

GO


EXEC sp_dbcmptlevel N'Evaluation', 90

GO

IF EXISTS (SELECT 1 FROM [sys].[databases] WHERE [name] = N'Evaluation') 
    ALTER DATABASE [Evaluation] SET  
	ALLOW_SNAPSHOT_ISOLATION OFF
GO

IF EXISTS (SELECT 1 FROM [sys].[databases] WHERE [name] = N'Evaluation') 
    ALTER DATABASE [Evaluation] SET  
	READ_COMMITTED_SNAPSHOT OFF
GO

IF EXISTS (SELECT 1 FROM [sys].[databases] WHERE [name] = N'Evaluation') 
    ALTER DATABASE [Evaluation] SET  
	MULTI_USER,
	CURSOR_CLOSE_ON_COMMIT OFF,
	CURSOR_DEFAULT LOCAL,
	AUTO_CLOSE OFF,
	AUTO_CREATE_STATISTICS ON,
	AUTO_SHRINK OFF,
	AUTO_UPDATE_STATISTICS ON,
	AUTO_UPDATE_STATISTICS_ASYNC ON,
	ANSI_NULL_DEFAULT ON,
	ANSI_NULLS ON,
	ANSI_PADDING ON,
	ANSI_WARNINGS ON,
	ARITHABORT ON,
	CONCAT_NULL_YIELDS_NULL ON,
	NUMERIC_ROUNDABORT OFF,
	QUOTED_IDENTIFIER ON,
	RECURSIVE_TRIGGERS OFF,
	RECOVERY FULL,
	PAGE_VERIFY NONE,
	DISABLE_BROKER,
	PARAMETERIZATION SIMPLE
	WITH ROLLBACK IMMEDIATE
GO

IF IS_SRVROLEMEMBER ('sysadmin') = 1
BEGIN

IF EXISTS (SELECT 1 FROM [sys].[databases] WHERE [name] = N'Evaluation') 
    EXEC sp_executesql N'
    ALTER DATABASE [Evaluation] SET  
	DB_CHAINING OFF,
	TRUSTWORTHY OFF'

END
ELSE
BEGIN
    RAISERROR(N'Unable to modify the database settings for DB_CHAINING or TRUSTWORTHY. You must be a SysAdmin in order to apply these settings.',0,1)
END

GO

USE [Evaluation]

GO
IF NOT EXISTS (SELECT * FROM master.dbo.syslogins WHERE loginname = N'NT AUTHORITY\NETWORK SERVICE')
CREATE LOGIN [NT AUTHORITY\NETWORK SERVICE] FROM WINDOWS
GO
CREATE USER [NT AUTHORITY\NETWORK SERVICE] FOR LOGIN [NT AUTHORITY\NETWORK SERVICE] WITH DEFAULT_SCHEMA=[dbo]
GRANT CONNECT TO [NT AUTHORITY\NETWORK SERVICE]
GO

PRINT N'Creating [dbo].[StudentEvaluation]'
GO
CREATE TABLE [dbo].[StudentEvaluation]
(
[Id] [int] NOT NULL IDENTITY(1, 1),
[CourseRunId] [int] NOT NULL,
[Name] [varchar] (50) COLLATE SQL_Latin1_General_CP1_CS_AS NOT NULL,
[EMail] [varchar] (50) COLLATE SQL_Latin1_General_CP1_CS_AS NULL,
[Company] [varchar] (50) COLLATE SQL_Latin1_General_CP1_CS_AS NULL,
[CourseMark] [int] NULL,
[CourseEvalNotes] [varchar] (100) COLLATE SQL_Latin1_General_CP1_CS_AS NULL,
[InstructorMark] [int] NULL,
[InstructorEvalNotes] [varchar] (100) COLLATE SQL_Latin1_General_CP1_CS_AS NULL,
[FacilitiesMark] [int] NULL,
[FacilitiesEvalNotes] [varchar] (100) COLLATE SQL_Latin1_General_CP1_CS_AS NULL
) ON [PRIMARY]
GO
PRINT N'Creating primary key [PK_STUDENT_EVALUATION] on [dbo].[StudentEvaluation]'
GO
ALTER TABLE [dbo].[StudentEvaluation] ADD CONSTRAINT [PK_STUDENT_EVALUATION] PRIMARY KEY CLUSTERED  ([Id]) ON [PRIMARY]
GO
PRINT N'Creating [dbo].[add_courseEvaluation]'
GO
CREATE PROCEDURE [dbo].[add_courseEvaluation]
	@CourseRunId int,
	@Name varchar(50),
	@EMail varchar(50),
	@Company varchar(50),
	@CourseMark int,
	@CourseEvalNotes varchar(100),
	@InstructorMark int,
	@InstructorEvalNotes varchar(100),
	@FacilitiesMark int,
	@FacilitiesEvalNotes varchar(100)
AS
	SET NOCOUNT ON
	
	IF(SELECT COUNT(*) FROM Course WHERE Id = @CourseRunId) = 0
	BEGIN
	    RETURN 101;
	END    

	INSERT INTO StudentEvaluation (	[CourseRunId], [Name], [EMail], [Company], [CourseMark], [CourseEvalNotes], [InstructorMark], [InstructorEvalNotes], [FacilitiesMark], [FacilitiesEvalNotes] ) 
		VALUES(	@CourseRunId, @Name, @EMail, @Company, @CourseMark, @CourseEvalNotes, @InstructorMark, @InstructorEvalNotes, @FacilitiesMark, @FacilitiesEvalNotes)

	RETURN @@ERROR;
GO
PRINT N'Creating [dbo].[CourseRun]'
GO
CREATE TABLE [dbo].[CourseRun]
(
[Id] [int] NOT NULL IDENTITY(1, 1),
[CourseId] [int] NOT NULL,
[LocationId] [int] NOT NULL,
[RunDate] [datetime] NOT NULL
) ON [PRIMARY]
GO
PRINT N'Creating primary key [PK_COURSERUN] on [dbo].[CourseRun]'
GO
ALTER TABLE [dbo].[CourseRun] ADD CONSTRAINT [PK_COURSERUN] PRIMARY KEY CLUSTERED  ([Id]) ON [PRIMARY]
GO
PRINT N'Creating [dbo].[Course]'
GO
CREATE TABLE [dbo].[Course]
(
[Id] [int] NOT NULL IDENTITY(1, 1),
[CourseId] [varchar] (5) COLLATE SQL_Latin1_General_CP1_CS_AS NOT NULL,
[Name] [varchar] (50) COLLATE SQL_Latin1_General_CP1_CS_AS NOT NULL,
[Description] [varchar] (50) COLLATE SQL_Latin1_General_CP1_CS_AS NOT NULL
) ON [PRIMARY]
GO
PRINT N'Creating primary key [PK_COURSE] on [dbo].[Course]'
GO
ALTER TABLE [dbo].[Course] ADD CONSTRAINT [PK_COURSE] PRIMARY KEY CLUSTERED  ([Id]) ON [PRIMARY]
GO
PRINT N'Creating [dbo].[add_course]'
GO
CREATE PROCEDURE [dbo].[add_course]
	@courseId varchar(5), 
	@name varchar(50), 
	@description varchar(500)
AS
	SET NOCOUNT ON
	
	IF(SELECT COUNT(*) FROM Course WHERE CourseId = @courseId) = 1
	BEGIN
	    RETURN 101;
	END    

	INSERT INTO Course ([CourseId], [Name], [Description]) VALUES(@courseId, @name, @description)

	RETURN @@ERROR;
GO
PRINT N'Creating [dbo].[get_evalsForCourseById]'
GO
CREATE PROCEDURE [dbo].[get_evalsForCourseById]
	@courseRunId int 
AS
	SET NOCOUNT ON
	
	IF(SELECT COUNT(*) FROM StudentEvaluation WHERE @courseRunId=CourseRunId) = 0
	BEGIN
	    RETURN 101;
	END    

	SELECT 	[Name], [EMail], [Company], [CourseMark], [CourseEvalNotes],
	[InstructorMark], [InstructorEvalNotes], [FacilitiesMark], [FacilitiesEvalNotes] 
	  FROM 
		StudentEvaluation
	  WHERE 
		@courseRunId=CourseRunId
	
	RETURN @@ERROR;
GO
PRINT N'Creating [dbo].[Location]'
GO
CREATE TABLE [dbo].[Location]
(
[Id] [int] NOT NULL IDENTITY(1, 1),
[Name] [varchar] (50) COLLATE SQL_Latin1_General_CP1_CS_AS NOT NULL,
[Description] [varchar] (500) COLLATE SQL_Latin1_General_CP1_CS_AS NOT NULL
) ON [PRIMARY]
GO
PRINT N'Creating primary key [PK_LOCATIONS] on [dbo].[Location]'
GO
ALTER TABLE [dbo].[Location] ADD CONSTRAINT [PK_LOCATIONS] PRIMARY KEY CLUSTERED  ([Id]) ON [PRIMARY]
GO
PRINT N'Creating [dbo].[add_courseRun]'
GO
CREATE PROCEDURE [dbo].[add_courseRun]
	@courseId int, 
    @locationId int, 
	@runDate DateTime
AS
	SET NOCOUNT ON

	IF(SELECT COUNT(*) FROM CourseRun 
		WHERE CourseId = @courseId
		AND LocationId = @locationId
		AND RunDate = @runDate) = 1
	BEGIN
	    RETURN 101;
	END    


	INSERT INTO CourseRun ([CourseId], [LocationId], [RunDate]) VALUES(@courseId, @locationId, @runDate)

	RETURN @@ERROR;
GO
PRINT N'Creating [dbo].[add_location]'
GO
CREATE PROCEDURE [dbo].[add_location]
	@name varchar(50), 
	@description varchar(500)
AS
	SET NOCOUNT ON
	IF(SELECT COUNT(*) FROM Location WHERE Location.Name = @name) = 1
	BEGIN
	    return 101;
	END    
	INSERT INTO Location ([Name], [Description]) VALUES(@name, @description)
	
	RETURN @@ERROR;
GO
PRINT N'Creating [dbo].[get_evalsByCourseIdAndLocation]'
GO
CREATE PROCEDURE [dbo].[get_evalsByCourseIdAndLocation]
	@courseid int,
	@locationid int,
	@date DateTime
AS
	SET NOCOUNT ON
	IF(SELECT COUNT(*) FROM CourseRun WHERE @courseid=CourseId AND @locationid=LocationId AND @date=RunDate) = 0
	BEGIN
	    RETURN 101;
	END    

	SELECT 	[Name], [EMail], [Company], [CourseMark], [CourseEvalNotes], [InstructorMark],
			[InstructorEvalNotes], [FacilitiesMark], [FacilitiesEvalNotes]
		FROM 
			StudentEvaluation AS S
		JOIN 
			CourseRun AS C
		ON
			C.CourseId=S.CourseRunId
		WHERE
			@courseid=CourseId and @locationid=LocationId 
			 AND C.RunDate=@date

	
	RETURN @@ERROR;
GO
PRINT N'Creating [dbo].[get_courseRuns]'
GO
CREATE PROCEDURE [dbo].[get_courseRuns]
AS
	SET NOCOUNT ON
	
	SELECT CourseRun.Id, 'CourseName'=Course.Name, 'CourseDescription'=Course.Description, 'LocationName'=Location.Name, 'LocationDescription'=Location.Description, RunDate 
	FROM 
		CourseRun
	JOIN
		Location
	ON
		CourseRun.LocationId=Location.Id
	JOIN
		Course
	ON
		CourseRun.CourseId=Course.Id
	
	RETURN @@ERROR;
GO
PRINT N'Adding foreign keys to [dbo].[CourseRun]'
GO
ALTER TABLE [dbo].[CourseRun] ADD
CONSTRAINT [FK_COURSERUN_COURSE] FOREIGN KEY ([CourseId]) REFERENCES [dbo].[Course] ([Id]),
CONSTRAINT [FK_COURSERUN_LOCATION] FOREIGN KEY ([LocationId]) REFERENCES [dbo].[Location] ([Id])
GO
PRINT N'Adding foreign keys to [dbo].[StudentEvaluation]'
GO
ALTER TABLE [dbo].[StudentEvaluation] ADD
CONSTRAINT [FK_STUDENTEVALUATION_COURSERUN] FOREIGN KEY ([CourseRunId]) REFERENCES [dbo].[CourseRun] ([Id])
GO

GRANT CONNECT TO [NT AUTHORITY\NETWORK SERVICE]
GO
GRANT CONNECT TO [NT AUTHORITY\NETWORK SERVICE]

GO

GO



EXEC sp_addrolemember N'db_owner', N'NT AUTHORITY\NETWORK SERVICE'

GO

GO


INSERT INTO Course ([CourseId], [Name], [Description]) VALUES('RT116', 'Intro to OOP', 'Learn object oriented programming')
INSERT INTO Course ([CourseId], [Name], [Description]) VALUES('RT224', 'Data Structures',  'Apply your OOP skills')
INSERT INTO Course ([CourseId], [Name], [Description]) VALUES('RT350', 'Compiler Methods', 'Learn how a compiler works')
INSERT INTO Course ([CourseId], [Name], [Description]) VALUES('RT555', 'Essential Source Control', 'Check your code in')

INSERT INTO Location ([Name], [Description]) VALUES('Eugene', 'Wet and Gloomy')
INSERT INTO Location ([Name], [Description]) VALUES('KFalls', 'Bright and Sunny')
INSERT INTO Location ([Name], [Description]) VALUES('Boston', 'Hot and Humid')

INSERT INTO CourseRun ([CourseId], [LocationId], [RunDate]) VALUES(1, 1, '01/01/2010')
INSERT INTO CourseRun ([CourseId], [LocationId], [RunDate]) VALUES(1, 2, '01/03/2010')
INSERT INTO CourseRun ([CourseId], [LocationId], [RunDate]) VALUES(1, 3, '01/04/2010')
INSERT INTO CourseRun ([CourseId], [LocationId], [RunDate]) VALUES(4, 1, '01/06/2010')
INSERT INTO CourseRun ([CourseId], [LocationId], [RunDate]) VALUES(2, 3, '01/06/2010')
INSERT INTO CourseRun ([CourseId], [LocationId], [RunDate]) VALUES(4, 3, '01/07/2010')
INSERT INTO CourseRun ([CourseId], [LocationId], [RunDate]) VALUES(3, 2, '01/08/2010')
INSERT INTO CourseRun ([CourseId], [LocationId], [RunDate]) VALUES(2, 1, '01/02/2010')
INSERT INTO CourseRun ([CourseId], [LocationId], [RunDate]) VALUES(3, 1, '01/02/2010')
INSERT INTO CourseRun ([CourseId], [LocationId], [RunDate]) VALUES(1, 2, '01/03/2010')
