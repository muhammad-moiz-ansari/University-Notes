import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import javafx.scene.control.cell.PropertyValueFactory;

import java.sql.*;

public class SimpleFXTable extends Application {

    TableView<User> table = new TableView<>();
    TextField txtName = new TextField();

    @Override
    public void start(Stage stage) throws Exception {

        txtName.setPromptText("Enter Name");
        Button btnAdd = new Button("Add");

        // Columns
        TableColumn<User, Integer> colId = new TableColumn<>("ID");
        colId.setCellValueFactory(new PropertyValueFactory<>("id"));

        TableColumn<User, String> colName = new TableColumn<>("Name");
        colName.setCellValueFactory(new PropertyValueFactory<>("name"));

        table.getColumns().addAll(colId, colName);

        loadData();

        // 🔥 BUTTON ACTION
        btnAdd.setOnAction(e -> {
            insertUser(txtName.getText());
            table.getItems().clear();
            loadData();
            txtName.clear();
        });

        VBox root = new VBox(10, txtName, btnAdd, table);
        stage.setScene(new Scene(root, 300, 300));
        stage.setTitle("JavaFX Example");
        stage.show();
    }

    private void insertUser(String name) {
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

    private void loadData() {
        try {
            Connection con = DriverManager.getConnection(
                "jdbc:mysql://localhost:3306/testdb",
                "root",
                "password"
            );
            Statement st = con.createStatement();
            ResultSet rs = st.executeQuery("SELECT * FROM users");

            while (rs.next()) {
                table.getItems().add(
                    new User(rs.getInt("id"), rs.getString("name"))
                );
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        launch(args);
    }
}