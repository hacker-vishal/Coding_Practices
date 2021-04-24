using System.Collections.Generic;
using System.Data.SqlClient;

namespace DAL
{
    public class DataOrm
    {
        public int DataID { get; set; }
        public string DataInfo { get; set; }
        public int DataKey { get; set; }
    }
    public interface IDAL
    {
        int InsertData(DataOrm dataOrm);
        int UpdateData(DataOrm dataOrm);
        int DeleteData(int id);
        List<DataOrm> GetAllData();
        DataOrm GetData(int id);
    }
    class DalEmp : IDAL
    {
        SqlConnection cnn;
        SqlCommand cmd;
        public DalEmp(string cnnStr)
        {
            cnn = new SqlConnection(cnnStr);
            cmd = new SqlCommand();
            cmd.Connection = cnn;
        }
        public int DeleteData(int id)
        {
            cmd.CommandText = $"delete from Employee where EmpID={id}";
            cnn.Open();
            int affetcted = cmd.ExecuteNonQuery();
            cnn.Close();
            return affetcted;
        }

        public List<DataOrm> GetAllData()
        {
            List<DataOrm> lstOrm = new List<DataOrm>();
            cmd.CommandText = "select * from Employee";
            cnn.Open();
            SqlDataReader reader = cmd.ExecuteReader(System.Data.CommandBehavior.CloseConnection);
            while(reader.Read())
            {
                lstOrm.Add(new DataOrm { DataID = (int)reader[0], DataInfo = reader[1].ToString(), DataKey = (int)reader[2] });
            }
            reader.Close();
            return lstOrm;
        }

        public DataOrm GetData(int id)
        {
            cmd.CommandText = $"select * from Employee where EmpID={id}";
            cnn.Open();
            DataOrm orm = null;
            SqlDataReader reader = cmd.ExecuteReader(System.Data.CommandBehavior.CloseConnection);
            if (reader.Read())
                orm = new DataOrm { DataID = (int)reader[0], DataInfo = reader[1].ToString(), DataKey = (int)reader[2] };
            reader.Close();
            return orm;
        }

        public int InsertData(DataOrm dataOrm)
        {
            cmd.CommandText = $"insert into Employee values({dataOrm.DataID},'{dataOrm.DataInfo}',{dataOrm.DataKey})";
            cnn.Open();
            int affetcted = cmd.ExecuteNonQuery();
            cnn.Close();
            return affetcted;
        }

        public int UpdateData(DataOrm dataOrm)
        {
            
            cmd.CommandText = $"update Employee set EmpName='{dataOrm.DataInfo}',EmpDept={dataOrm.DataKey} where EmpID={dataOrm.DataID}";
            cnn.Open();
            int affetcted = cmd.ExecuteNonQuery();
            cnn.Close();
            return affetcted;
        }
    }
    public static class DALFactory
    {
        public static IDAL GetDalFactory(string cnnStr)
        {
            return new DalEmp(cnnStr);
        }
    }
}
