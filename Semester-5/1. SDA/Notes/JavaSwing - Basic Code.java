import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.sql.*;

public class SimpleSwing {

    static DefaultTableModel model;

    public static void main(String[] args) {

        JFrame frame = new JFrame("Swing Example");

        JTextField txtName = new JTextField();
        JButton btnAdd = new JButton("Add");

        model = new DefaultTableModel(new String[]{"ID", "Name"}, 0);
        JTable table = new JTable(model);

        loadData();

        // 🔥 BUTTON ACTION
        btnAdd.addActionListener(e -> {
            insertUser(txtName.getText());
            model.setRowCount(0);
            loadData();
            txtName.setText("");
        });

        frame.setLayout(new GridLayout(4, 1));
        frame.add(txtName);
        frame.add(btnAdd);
        frame.add(new JScrollPane(table));

        frame.setSize(300, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }

    static void insertUser(String name) {
        try {
            Connection con = DriverManager.getConnection(
                "jdbc:mysql://localhost:3306/testdb",
                "root",
                "password"
            );
            PreparedStatement ps =
                con.prepareStatement("INSERT INTO users(name) VALUES(?)");
            ps.setString(1, name);
            ps.executeUpdate();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static void loadData() {
        try {
            Connection con = DriverManager.getConnection(
                "jdbc:mysql://localhost:3306/testdb",
                "root",
                "password"
            );
            Statement st = con.createStatement();
            ResultSet rs = st.executeQuery("SELECT * FROM users");

            while (rs.next()) {
                model.addRow(new Object[]{
                    rs.getInt("id"),
                    rs.getString("name")
                });
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}