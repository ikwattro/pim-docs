**Operating Systems**

Akeneo PIM only works on Linux servers. The application’s behaviour has been tested on several operating systems. We cannot guarantee the behaviour of the application on servers different from:

+------------------------+-------------------+
| Debian (Linux)         | ≥ 8 (64 bits)     |
+------------------------+-------------------+
| Ubuntu (Linux)         | ≥ 14.04 (64 bits) |
+------------------------+-------------------+
| CentOS / RHEL* (Linux) | ≥ 7               |
+------------------------+-------------------+

* RHEL stands for Red Hat Enterprise Linux.

**Web server and configuration**

We can only guarantee the behaviour on the following web server:

+-------------------+-------+
| Apache web server | ≥ 2.4 |
+-------------------+-------+

The web server will also need the following libraries and modules:

+--------------+-----------------------------------------+
| mod rewrite  |  Required                               |
+--------------+-----------------------------------------+
| mod php5     |  Required (no CGI, no FastCGI, nor FPM) |
+--------------+-----------------------------------------+

**PHP required modules and configuration**

+-------------+---------------------------+
| PHP         | 5.6                       |
+-------------+---------------------------+
| php5-curl   | No specific configuration |
+-------------+---------------------------+
| php5-gd     | No specific configuration |
+-------------+---------------------------+
| php5-intl   | No specific configuration |
+-------------+---------------------------+
| php5-mcrypt | No specific configuration |
+-------------+---------------------------+
| php5-apcu   | apc.enable_cli=1          |
+-------------+---------------------------+

Besides these modules, the following configuration is the minimal configuration required:

.. include:: /reference/technical_information/php_ini.rst.inc

.. _database-servers:

**Database servers**

.. include:: /reference/technical_information/choose_database.rst.inc

+-----------------+---------------------+
| MySQL (SQL)     | 5.1 ≤ version ≤ 5.6 |
+-----------------+---------------------+
| MongoDB (NoSQL) | 2.4 or 2.6          |
+-----------------+---------------------+

.. warning::

  Due to changes in its API, MongoDB 3.0 is not supported.

.. _ONLY_FULL_GROUP_BY: http://dev.mysql.com/doc/refman/5.7/en/sql-mode.html#sqlmode_only_full_group_by

.. warning::

  MySQL 5.7 is not officialy supported but works as experimental mode if you disable the ONLY_FULL_GROUP_BY_ mode.

Depending on the configuration you pick, you will need to respect parts or all of the following requirements.

**MySQL**

To use this database you will also require the distribution package:

+--------------+----------+
| mysql-server | Required |
+--------------+----------+

and the following PHP modules:

+------------+----------+
| php5-mysql | Required |
+------------+----------+

**MongoDB**

To use this database you will also require the distribution package:

+----------------+----------+
| mongodb-server | Required |
+----------------+----------+

and the following php modules:

+------------+----------+
| php5-mongo | Required |
+------------+----------+

**Network**

The following ports should be opened on the server host for the PIM to work properly:

+---------------+-----------------------------------------------------------+---------------------------+
| HTTP or HTTPS | 80 or 443                                                 | Required                  |
+---------------+-----------------------------------------------------------+---------------------------+
| MySQL         | unix socket or 3306 (if MySQL server on a different host) | Required                  |
+---------------+-----------------------------------------------------------+---------------------------+
| SSH           | 22                                                        | Required (for deployment) |
+---------------+-----------------------------------------------------------+---------------------------+

**Files and folders access rights**

Most of the application folders and files require only read access. Here is a list of folders that also need write access for the Apache user:

+-------------+--------------------------------------------------------------------------------+
| app/cache   | Contains application cache files                                               |
+-------------+--------------------------------------------------------------------------------+
| app/logs    | Contains application log files                                                 |
+-------------+--------------------------------------------------------------------------------+
| app/uploads | Contains files uploaded to the application by users or during import processes |
+-------------+--------------------------------------------------------------------------------+
| web         | Contains the web assets required by the application                            |
+-------------+--------------------------------------------------------------------------------+

These permissions are the ones required by the Symfony Framework (see its official documentation for more information).

Akeneo PIM application uses an abstraction layer called Flysystem to store media and files uploaded from the application. By default, Flysystem is configured to store these files on the application server, but this configuration can easily be changed in favor of, for example, a distributed remote storage system (see Flysystem documentation for more information).

The app/uploads folder could be located elsewhere depending on the configuration you defined in the parameters.yml of your Akeneo PIM application instance.

Please note that neither the Apache user or the CLI should be the root user of the system.
