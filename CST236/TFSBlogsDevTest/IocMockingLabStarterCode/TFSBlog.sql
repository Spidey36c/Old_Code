IF  EXISTS (SELECT name FROM sys.databases WHERE name = N'TFSBlog')
DROP DATABASE [TFSBlog]
GO


USE [master]
GO

CREATE DATABASE [TFSBlog] 
GO

ALTER DATABASE [TFSBlog] SET COMPATIBILITY_LEVEL = 100
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [TFSBlog].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [TFSBlog] SET ANSI_NULL_DEFAULT OFF
GO
ALTER DATABASE [TFSBlog] SET ANSI_NULLS OFF
GO
ALTER DATABASE [TFSBlog] SET ANSI_PADDING OFF
GO
ALTER DATABASE [TFSBlog] SET ANSI_WARNINGS OFF
GO
ALTER DATABASE [TFSBlog] SET ARITHABORT OFF
GO
ALTER DATABASE [TFSBlog] SET AUTO_CLOSE OFF
GO
ALTER DATABASE [TFSBlog] SET AUTO_CREATE_STATISTICS ON
GO
ALTER DATABASE [TFSBlog] SET AUTO_SHRINK OFF
GO
ALTER DATABASE [TFSBlog] SET AUTO_UPDATE_STATISTICS ON
GO
ALTER DATABASE [TFSBlog] SET CURSOR_CLOSE_ON_COMMIT OFF
GO
ALTER DATABASE [TFSBlog] SET CURSOR_DEFAULT  GLOBAL
GO
ALTER DATABASE [TFSBlog] SET CONCAT_NULL_YIELDS_NULL OFF
GO
ALTER DATABASE [TFSBlog] SET NUMERIC_ROUNDABORT OFF
GO
ALTER DATABASE [TFSBlog] SET QUOTED_IDENTIFIER OFF
GO
ALTER DATABASE [TFSBlog] SET RECURSIVE_TRIGGERS OFF
GO
ALTER DATABASE [TFSBlog] SET  DISABLE_BROKER
GO
ALTER DATABASE [TFSBlog] SET AUTO_UPDATE_STATISTICS_ASYNC OFF
GO
ALTER DATABASE [TFSBlog] SET DATE_CORRELATION_OPTIMIZATION OFF
GO
ALTER DATABASE [TFSBlog] SET TRUSTWORTHY OFF
GO
ALTER DATABASE [TFSBlog] SET ALLOW_SNAPSHOT_ISOLATION OFF
GO
ALTER DATABASE [TFSBlog] SET PARAMETERIZATION SIMPLE
GO
ALTER DATABASE [TFSBlog] SET READ_COMMITTED_SNAPSHOT OFF
GO
ALTER DATABASE [TFSBlog] SET HONOR_BROKER_PRIORITY OFF
GO
ALTER DATABASE [TFSBlog] SET  READ_WRITE
GO
ALTER DATABASE [TFSBlog] SET RECOVERY FULL
GO
ALTER DATABASE [TFSBlog] SET  MULTI_USER
GO
ALTER DATABASE [TFSBlog] SET PAGE_VERIFY CHECKSUM
GO
ALTER DATABASE [TFSBlog] SET DB_CHAINING OFF
GO
USE [TFSBlog]
GO
/****** Object:  Table [dbo].[Comments]    Script Date: 06/22/2010 11:32:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Comments](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[PostId] [int] NOT NULL,
	[Value] [nvarchar](max) NOT NULL,
	[Name] [nvarchar](150) NULL,
	[EMail] [nvarchar](150) NULL,
	[DateCommented] [datetime] NOT NULL,
 CONSTRAINT [PK_Comments] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Users]    Script Date: 06/22/2010 11:32:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Users](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[BlogId] [int] NULL,
	[Name] [nvarchar](50) NOT NULL,
	[EMail] [nvarchar](150) NOT NULL,
	[Salt] [nvarchar](50) NOT NULL,
	[HashedPassword] [nvarchar](150) NOT NULL,
 CONSTRAINT [PK_Users] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Posts]    Script Date: 06/22/2010 11:32:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Posts](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[BlogId] [int] NOT NULL,
	[Title] [nvarchar](150) NOT NULL,
	[Value] [nvarchar](max) NOT NULL,
	[DatePosted] [datetime] NOT NULL,
 CONSTRAINT [PK_Post] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Blogs]    Script Date: 06/22/2010 11:32:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Blogs](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[Name] [nvarchar](150) NOT NULL,
	[SubTitle] [nvarchar](150) NOT NULL,
	[UserId] [int] NOT NULL,
 CONSTRAINT [PK_Blogs] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  ForeignKey [FK_Comments_Post]    Script Date: 06/22/2010 11:32:57 ******/
ALTER TABLE [dbo].[Comments]  WITH CHECK ADD  CONSTRAINT [FK_Comments_Post] FOREIGN KEY([PostId])
REFERENCES [dbo].[Posts] ([Id])
GO
ALTER TABLE [dbo].[Comments] CHECK CONSTRAINT [FK_Comments_Post]
GO
/****** Object:  ForeignKey [FK_Users_Blogs]    Script Date: 06/22/2010 11:32:57 ******/
ALTER TABLE [dbo].[Users]  WITH CHECK ADD  CONSTRAINT [FK_Users_Blogs] FOREIGN KEY([BlogId])
REFERENCES [dbo].[Blogs] ([Id])
GO
ALTER TABLE [dbo].[Users] CHECK CONSTRAINT [FK_Users_Blogs]
GO
/****** Object:  ForeignKey [FK_Post_Blogs]    Script Date: 06/22/2010 11:32:57 ******/
ALTER TABLE [dbo].[Posts]  WITH CHECK ADD  CONSTRAINT [FK_Post_Blogs] FOREIGN KEY([BlogId])
REFERENCES [dbo].[Blogs] ([Id])
GO
ALTER TABLE [dbo].[Posts] CHECK CONSTRAINT [FK_Post_Blogs]
GO
/****** Object:  ForeignKey [FK_Blogs_Users]    Script Date: 06/22/2010 11:32:57 ******/
ALTER TABLE [dbo].[Blogs]  WITH CHECK ADD  CONSTRAINT [FK_Blogs_Users] FOREIGN KEY([UserId])
REFERENCES [dbo].[Users] ([Id])
GO
ALTER TABLE [dbo].[Blogs] CHECK CONSTRAINT [FK_Blogs_Users]
GO

SET IDENTITY_INSERT [users] off
SET IDENTITY_INSERT [blogs] off
SET IDENTITY_INSERT [posts] off
GO
delete from [Users];
delete from [Posts];
delete from [Blogs];
GO
DBCC CHECKIDENT([Users], RESEED, 1)
DBCC CHECKIDENT([Blogs], RESEED, 1)
DBCC CHECKIDENT([Posts], RESEED, 1)
GO
insert into [Users] (name, email, Salt, HashedPassword) values('Calvin', 'Calvin.aldwell@oit.edu', '', '')
insert into [Users] (name, email, Salt, HashedPassword) values('Todd', 'todd.breedlove@oit.edu', '', '')
insert into [Users] (name, email, Salt, HashedPassword) values('Randy', 'randal.albert@oit.edu', '', '')
GO
insert into [blogs] (userid, name, SubTitle) values(1, 'Calvin Work Blog', '')
insert into [blogs] (userid, name, SubTitle) values(1, 'Randy Personal Blog', '')
insert into [blogs] (userid, name, SubTitle) values(2, 'Todd Main Blog', '')
insert into [blogs] (userid, name, SubTitle) values(2, 'Ralph Main Blog', '')
GO
insert into [Posts] (blogid, title, value, DatePosted) values (1, 'title 11', 'entry 11', 2010-01-01)
insert into [Posts] (blogid, title, value, DatePosted) values (1, 'title 12', 'entry 12', 2010-01-01)
insert into [Posts] (blogid, title, value, DatePosted) values (1, 'title 13', 'entry 13', 2010-01-01)
insert into [Posts] (blogid, title, value, DatePosted) values (2, 'title 21', 'entry 21', 2010-01-01)
insert into [Posts] (blogid, title, value, DatePosted) values (2, 'title 22', 'entry 22', 2010-01-01)
insert into [Posts] (blogid, title, value, DatePosted) values (2, 'title 23', 'entry 23', 2010-01-01)
insert into [Posts] (blogid, title, value, DatePosted) values (3, 'title 31', 'entry 31', 2010-01-01)
insert into [Posts] (blogid, title, value, DatePosted) values (4, 'title 41', 'entry 41', 2010-01-01)
GO

SET IDENTITY_INSERT users on

GO