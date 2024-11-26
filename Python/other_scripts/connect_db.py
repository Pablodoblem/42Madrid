import mysql.connector

conn = mysql.connector.connect(
    host="db5016660208.hosting-data.io",      # o la IP del servidor
    user="dbu1498781",
    password="kyXbb5c*GPgK5W*",
    database="dbs13499224"
)

cursor = conn.cursor()
cursor.execute("SELECT * FROM test_table;")
for row in cursor.fetchall():
    print(row)

conn.close()