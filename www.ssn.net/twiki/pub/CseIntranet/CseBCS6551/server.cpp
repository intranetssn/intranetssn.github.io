//LOGIN CODE

package secure;
import java.sql.*;
import javax.swing.*;



public class ExporterLogin extends javax.swing.JFrame {
    
      Connection con=null;
       PreparedStatement  pst=null;
       ResultSet rs=null;
   
    public ExporterLogin() {
        initComponents();
    }

    
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">                          
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        ExpLgUserid = new javax.swing.JTextField();
        ExpLgPassword = new javax.swing.JPasswordField();
        jLabel2 = new javax.swing.JLabel();
        ExpLgButton = new javax.swing.JButton();
        jLabel3 = new javax.swing.JLabel();
        jLabel1 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        HomeButton = new javax.swing.JButton();
        jLabel11 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Foreign Trading System");

        ExpLgUserid.setFont(new java.awt.Font("Comic Sans MS", 0, 14)); // NOI18N
        ExpLgUserid.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ExpLgUseridActionPerformed(evt);
            }
        });

        ExpLgPassword.setFont(new java.awt.Font("Comic Sans MS", 0, 14)); // NOI18N

        jLabel2.setFont(new java.awt.Font("Comic Sans MS", 0, 18)); // NOI18N
        jLabel2.setText("USERID :");

        ExpLgButton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/secure/loginbutton.JPG"))); // NOI18N
        ExpLgButton.setBorder(new javax.swing.border.SoftBevelBorder(javax.swing.border.BevelBorder.RAISED));
        ExpLgButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ExpLgButtonActionPerformed(evt);
            }
        });

        jLabel3.setFont(new java.awt.Font("Comic Sans MS", 0, 18)); // NOI18N
        jLabel3.setText("PASSWORD :");

        jLabel1.setFont(new java.awt.Font("Comic Sans MS", 1, 24)); // NOI18N
        jLabel1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/secure/elogin.png"))); // NOI18N

        jLabel4.setIcon(new javax.swing.ImageIcon(getClass().getResource("/secure/user.png"))); // NOI18N

        HomeButton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/secure/home.JPG"))); // NOI18N
        HomeButton.setBorder(new javax.swing.border.SoftBevelBorder(javax.swing.border.BevelBorder.RAISED));
        HomeButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                HomeButtonActionPerformed(evt);
            }
        });

        jLabel11.setIcon(new javax.swing.ImageIcon(getClass().getResource("/secure/fts8879.JPG"))); // NOI18N
        jLabel11.setText("jLabel9");

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                .addContainerGap(390, Short.MAX_VALUE)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(HomeButton, javax.swing.GroupLayout.PREFERRED_SIZE, 133, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(134, 134, 134)
                        .addComponent(ExpLgButton, javax.swing.GroupLayout.PREFERRED_SIZE, 130, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(jPanel1Layout.createSequentialGroup()
                            .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                .addComponent(jLabel3, javax.swing.GroupLayout.Alignment.TRAILING)
                                .addComponent(jLabel2, javax.swing.GroupLayout.Alignment.TRAILING))
                            .addGap(18, 18, 18)
                            .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                .addComponent(ExpLgUserid, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 220, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addComponent(ExpLgPassword, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 220, javax.swing.GroupLayout.PREFERRED_SIZE)))
                        .addComponent(jLabel1)))
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(368, 368, 368)
                        .addComponent(jLabel11, javax.swing.GroupLayout.PREFERRED_SIZE, 86, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(27, 27, 27)
                        .addComponent(jLabel4)))
                .addGap(111, 111, 111))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(45, 45, 45)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(jLabel11)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(jLabel1)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(jPanel1Layout.createSequentialGroup()
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                    .addComponent(ExpLgUserid, javax.swing.GroupLayout.PREFERRED_SIZE, 35, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(jLabel2))
                                .addGap(40, 40, 40)
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                    .addComponent(ExpLgPassword, javax.swing.GroupLayout.PREFERRED_SIZE, 37, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(jLabel3))
                                .addGap(141, 141, 141))
                            .addGroup(jPanel1Layout.createSequentialGroup()
                                .addGap(79, 79, 79)
                                .addComponent(jLabel4)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 122, Short.MAX_VALUE)))))
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(HomeButton, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(ExpLgButton, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(110, 110, 110))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>                        

    private void ExpLgUseridActionPerformed(java.awt.event.ActionEvent evt) {                                            
        // TODO add your handling code here:
    }                                           

    private void ExpLgButtonActionPerformed(java.awt.event.ActionEvent evt) {                                            
        
        String PassExpId=ExpLgUserid.getText();
        new ExporterNewPost(PassExpId).setVisible(false);
        new ExportersWallet(PassExpId).setVisible(false);
        new ExporterDashboard(PassExpId).setVisible(false);
        new ExporterMyPosts(PassExpId).setVisible(false);
        new ExporterDeletePost(PassExpId).setVisible(false);
        new ExporterUpdatePost(PassExpId).setVisible(false);
        new ExporterNewRequests(PassExpId).setVisible(false);
        new ExporterRejectForm(PassExpId).setVisible(false);
        new ExporterAcceptForm(PassExpId).setVisible(false);
        new ExporterCompletedDeals(PassExpId).setVisible(false);
        con=MySqlConnection.ConnectToDb();
       String Query="select * from explgntb where expid=? and password=?";
       this.setVisible(false);
       try
       {
           pst=con.prepareStatement(Query);
           pst.setString(1,ExpLgUserid.getText());
           pst.setString(2,ExpLgPassword.getText());
           rs=pst.executeQuery();
           if(rs.next())
           {
              ExporterDashboard ED = new ExporterDashboard();
              ED.setVisible(true);
           }   
           else
           {
               JOptionPane.showMessageDialog(null,"Invalid userid or password","Acess denied",JOptionPane.ERROR_MESSAGE);
               ExporterLogin EL = new ExporterLogin();
               EL.setVisible(true);
           }
           pst.close();
           con.close();
       }
       catch(Exception e)
       {
           JOptionPane.showMessageDialog(null,e);
       }
    }                                           

    private void HomeButtonActionPerformed(java.awt.event.ActionEvent evt) {                                           
        // TODO add your handling code here:
        Welcome W = new Welcome();
        W.setVisible(true);
        dispose();
        
    }                                          

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(ExporterLogin.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(ExporterLogin.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(ExporterLogin.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(ExporterLogin.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new ExporterLogin().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify                     
    private javax.swing.JButton ExpLgButton;
    private javax.swing.JPasswordField ExpLgPassword;
    private javax.swing.JTextField ExpLgUserid;
    private javax.swing.JButton HomeButton;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel11;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JPanel jPanel1;
    // End of variables declaration                   
}
**********************************************************************************************************************************
**********************************************************************************************************************************
//INSERT CODE
    
package secure;
import java.sql.*;
import javax.swing.*;
import java.util.*;
import java.awt.*;
import java.text.*;



public class ExporterNewPost extends javax.swing.JFrame {
    public static String ExpIdDsp;
    public static String CategoryToUpdate;
    Connection con=null;
       PreparedStatement  pst=null;
       ResultSet rs=null;
    
    public ExporterNewPost() {
        initComponents();
        
        Calendar now = Calendar.getInstance();
            int month = now.get(Calendar.MONTH);
            int day = now.get(Calendar.DAY_OF_MONTH);
            int year = now.get(Calendar.YEAR);
            PostProductDate.setText("" + (month + 1) + "/" + day + "/" + year);
             SimpleDateFormat sdf1 = new SimpleDateFormat("hh:mm: a");
             java.util.Date tt = new java.util.Date();
             String t = sdf1.format(tt);
             PostProductTime.setText(t);
    }
    
    public ExporterNewPost(String PassExpId)
    {
        ExpIdDsp = PassExpId;
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">                          
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        PostProductName = new javax.swing.JTextField();
        PostMinimunQuantity = new javax.swing.JTextField();
        PostMaximumQuantity = new javax.swing.JTextField();
        PostPricePerPiece = new javax.swing.JTextField();
        ExpNewPostUploadButton = new javax.swing.JButton();
        jLabel6 = new javax.swing.JLabel();
        ProductIdLabel = new javax.swing.JLabel();
        ExpNewPostResetButton = new javax.swing.JButton();
        BackBtn = new javax.swing.JButton();
        jLabel7 = new javax.swing.JLabel();
        PostProductDate = new javax.swing.JLabel();
        jLabel8 = new javax.swing.JLabel();
        PostProductTime = new javax.swing.JLabel();
        jLabel9 = new javax.swing.JLabel();
        PostCategory = new javax.swing.JComboBox<>();
        jLabel10 = new javax.swing.JLabel();
        jMenuBar2 = new javax.swing.JMenuBar();
        DashboardButton = new javax.swing.JMenu();
        MyPosts = new javax.swing.JMenu();
        MyWallet = new javax.swing.JMenu();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Foreign Trading System");

        jLabel1.setFont(new java.awt.Font("Comic Sans MS", 1, 18)); // NOI18N
        jLabel1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/secure/newpost.png"))); // NOI18N

        jLabel2.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        jLabel2.setText("Product Name:");

        jLabel3.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        jLabel3.setText("Minimun Quantity:");

        jLabel4.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        jLabel4.setText("Price Per Piece:");

        jLabel5.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        jLabel5.setText("Maximum Quantity:");

        PostProductName.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        PostProductName.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                PostProductNameActionPerformed(evt);
            }
        });

        PostMinimunQuantity.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N

        PostMaximumQuantity.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N

        PostPricePerPiece.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N

        ExpNewPostUploadButton.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        ExpNewPostUploadButton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/secure/upload.JPG"))); // NOI18N
        ExpNewPostUploadButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ExpNewPostUploadButtonActionPerformed(evt);
            }
        });

        jLabel6.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        jLabel6.setText("Product ID:");

        ProductIdLabel.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        ProductIdLabel.setText("ProductIdLabel");
        con = MySqlConnection.ConnectToDb();
        String Query1 = "SELECT PRODUCTID FROM EXPNEWPOST ORDER BY PRODUCTID DESC LIMIT 1 ";

        try
        {
            pst = con.prepareStatement(Query1);
            rs=pst.executeQuery(Query1);
            while(rs.next())
            {
                String IdDsp = rs.getString("PRODUCTID");
                int IdDsp1 = Integer.parseInt(IdDsp);
                IdDsp1++;
                ProductIdLabel.setText(""+IdDsp1);
            }
        }
        catch(Exception e)
        {
            JOptionPane.showMessageDialog(null, e);
        }

        ExpNewPostResetButton.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        ExpNewPostResetButton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/secure/reset.JPG"))); // NOI18N
        ExpNewPostResetButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ExpNewPostResetButtonActionPerformed(evt);
            }
        });

        BackBtn.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        BackBtn.setIcon(new javax.swing.ImageIcon(getClass().getResource("/secure/back.JPG"))); // NOI18N
        BackBtn.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BackBtnActionPerformed(evt);
            }
        });

        jLabel7.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        jLabel7.setText("Time:");

        PostProductDate.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        PostProductDate.setText("jLabel8");

        jLabel8.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        jLabel8.setText("Date:");

        PostProductTime.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        PostProductTime.setText("jLabel9");

        jLabel9.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        jLabel9.setText("Category:");

        PostCategory.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        PostCategory.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Mobiles", "Fashion", "Books", "Sorts", "Grocery", "Electronics and Appliances", "Appliances", "Jewellary", "Indian masala" }));

        jLabel10.setIcon(new javax.swing.ImageIcon(getClass().getResource("/secure/fts8879.JPG"))); // NOI18N
        jLabel10.setText("jLabel9");

        DashboardButton.setText("Dashboard");
        DashboardButton.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        DashboardButton.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                DashboardButtonMouseClicked(evt);
            }
        });
        jMenuBar2.add(DashboardButton);

        MyPosts.setText("My Posts");
        MyPosts.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        MyPosts.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                MyPostsMouseClicked(evt);
            }
        });
        jMenuBar2.add(MyPosts);

        MyWallet.setText("My Wallet");
        MyWallet.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        MyWallet.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                MyWalletMouseClicked(evt);
            }
        });
        jMenuBar2.add(MyWallet);

        setJMenuBar(jMenuBar2);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(462, 462, 462)
                        .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 262, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(jLabel10, javax.swing.GroupLayout.PREFERRED_SIZE, 88, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addContainerGap(399, Short.MAX_VALUE)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(jLabel5, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(jLabel2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(jLabel3, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(jLabel6, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(jLabel4, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(jLabel7, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(jLabel8, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(jLabel9, javax.swing.GroupLayout.PREFERRED_SIZE, 133, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(64, 64, 64)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(PostProductDate, javax.swing.GroupLayout.PREFERRED_SIZE, 146, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(PostProductTime, javax.swing.GroupLayout.PREFERRED_SIZE, 146, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(ProductIdLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 210, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                .addComponent(PostMaximumQuantity)
                                .addComponent(PostProductName)
                                .addComponent(PostMinimunQuantity)
                                .addComponent(PostPricePerPiece)
                                .addComponent(PostCategory, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                        .addGap(476, 476, 476)))
                .addGap(70, 70, 70))
            .addGroup(layout.createSequentialGroup()
                .addGap(328, 328, 328)
                .addComponent(BackBtn, javax.swing.GroupLayout.PREFERRED_SIZE, 81, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(122, 122, 122)
                .addComponent(ExpNewPostResetButton, javax.swing.GroupLayout.PREFERRED_SIZE, 103, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(120, 120, 120)
                .addComponent(ExpNewPostUploadButton, javax.swing.GroupLayout.PREFERRED_SIZE, 119, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addContainerGap(39, Short.MAX_VALUE)
                        .addComponent(jLabel1)
                        .addGap(27, 27, 27))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(48, 48, 48)
                        .addComponent(jLabel10, javax.swing.GroupLayout.DEFAULT_SIZE, 85, Short.MAX_VALUE)))
                .addGap(16, 16, 16)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabel6)
                    .addComponent(ProductIdLabel))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabel9)
                    .addComponent(PostCategory, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(PostProductName, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel2))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(PostMinimunQuantity, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel3))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(PostMaximumQuantity, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel5))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(PostPricePerPiece, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel4))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabel8)
                    .addComponent(PostProductDate))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(PostProductTime)
                    .addComponent(jLabel7))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 75, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(BackBtn, javax.swing.GroupLayout.PREFERRED_SIZE, 48, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(ExpNewPostResetButton, javax.swing.GroupLayout.PREFERRED_SIZE, 48, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(ExpNewPostUploadButton, javax.swing.GroupLayout.PREFERRED_SIZE, 48, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(90, 90, 90))
        );

        pack();
    }// </editor-fold>                        

    private void PostProductNameActionPerformed(java.awt.event.ActionEvent evt) {                                                
        // TODO add your handling code here:
         
    }                                               

    private void ExpNewPostUploadButtonActionPerformed(java.awt.event.ActionEvent evt) {                                                       
        // TODO add your handling code here:
        con=MySqlConnection.ConnectToDb();
             String ProductName = PostProductName.getText();
             String MinimumQuantity = PostMinimunQuantity.getText();
             int MinQty=Integer.parseInt(MinimumQuantity);
             String MaximumQuantity = PostMaximumQuantity.getText();
             int MaxQty=Integer.parseInt(MaximumQuantity);
             String PricePerPiece = PostPricePerPiece.getText();
             int Price=Integer.parseInt(PricePerPiece);
             java.util.Date date = new java.util.Date();
             java.sql.Date PostDate = new java.sql.Date(date.getTime());
             java.sql.Timestamp sqlTime=new java.sql.Timestamp(date.getTime());
             CategoryToUpdate = PostCategory.getSelectedItem().toString();
            
             String Query="INSERT INTO EXPNEWPOST (PRODUCTNAME,MINQTY,MAXQTY,PRICEPERPIECE,DATE,TIME,expid,category) VALUES (?,?,?,?,?,?,?,?)";
         try
         {
              pst=con.prepareStatement(Query);
              pst.setString(1,ProductName);
              pst.setInt(2,MinQty);
              pst.setInt(3,MaxQty);
              pst.setInt(4,Price);
              pst.setDate(5,PostDate);
              pst.setTimestamp(6, sqlTime); 
              pst.setString(7,ExpIdDsp);
              pst.setString(8, CategoryToUpdate);
             int ChkInsert = pst.executeUpdate();
              if( ChkInsert > 0)
              {
                  JOptionPane.showMessageDialog(null,"POSTED");
                  ExporterNewPost ENP = new ExporterNewPost();
                  ENP.setVisible(true);
                  dispose();
                  
              }
              else 
              {
                  JOptionPane.showMessageDialog(null,"Enter the details again","INVALID DATA",JOptionPane.ERROR_MESSAGE);
                  
              }      
                 pst.close();
                con.close();

              
          }
         catch(Exception e)
         {
              JOptionPane.showMessageDialog(null,e);
         }
    }                                                      

    private void ExpNewPostResetButtonActionPerformed(java.awt.event.ActionEvent evt) {                                                      
        // TODO add your handling code here:
        PostProductName.setText("");
        PostMinimunQuantity.setText("");
        PostMaximumQuantity.setText("");
        PostPricePerPiece.setText("");
        //ProductIdLabel.setText("");
    }                                                     

    private void BackBtnActionPerformed(java.awt.event.ActionEvent evt) {                                        
        // TODO add your handling code here:
       ExporterDashboard ED = new ExporterDashboard();
       this.setVisible(false);
        ED.setVisible(true);
        dispose();
        
    }                                       

    private void DashboardButtonMouseClicked(java.awt.event.MouseEvent evt) {                                             
        // TODO add your handling code here:
        ExporterDashboard ED = new ExporterDashboard();
        ED.setVisible(true);
        dispose();
    }                                            

    private void MyPostsMouseClicked(java.awt.event.MouseEvent evt) {                                     
        // TODO add your handling code here:
        ExporterMyPosts EMP = new ExporterMyPosts();
        EMP.setVisible(true);
        dispose();
    }                                    

    private void MyWalletMouseClicked(java.awt.event.MouseEvent evt) {                                      
        // TODO add your handling code here:
        ExportersWallet EW = new ExportersWallet();
        EW.setVisible(true);
        dispose();
    }                                     

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(ExporterNewPost.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(ExporterNewPost.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(ExporterNewPost.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(ExporterNewPost.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new ExporterNewPost().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify                     
    private javax.swing.JButton BackBtn;
    private javax.swing.JMenu DashboardButton;
    private javax.swing.JButton ExpNewPostResetButton;
    private javax.swing.JButton ExpNewPostUploadButton;
    private javax.swing.JMenu MyPosts;
    private javax.swing.JMenu MyWallet;
    private javax.swing.JComboBox<String> PostCategory;
    private javax.swing.JTextField PostMaximumQuantity;
    private javax.swing.JTextField PostMinimunQuantity;
    private javax.swing.JTextField PostPricePerPiece;
    private javax.swing.JLabel PostProductDate;
    private javax.swing.JTextField PostProductName;
    private javax.swing.JLabel PostProductTime;
    private javax.swing.JLabel ProductIdLabel;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel10;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JMenuBar jMenuBar2;
    // End of variables declaration                   
}
**********************************************************************************************************************************
**********************************************************************************************************************************
//UPDATE CODE:

package secure;
import java.sql.*;
import java.text.SimpleDateFormat;
import javax.swing.*;
import java.util.*;
import net.proteanit.sql.DbUtils;


public class ExporterUpdatePost extends javax.swing.JFrame {
        public static String GetExpId;
        public static String SelectedItemToUpdate;
       Connection con=null;
       PreparedStatement  pst=null;
       ResultSet rs=null;
   
       public ExporterUpdatePost(String PassExpId)
       {
           GetExpId = PassExpId;
       }
       
       
    public ExporterUpdatePost() 
    {
        initComponents();
         Calendar now = Calendar.getInstance();
       int month = now.get(Calendar.MONTH);
            int day = now.get(Calendar.DAY_OF_MONTH);
            int year = now.get(Calendar.YEAR);
            UpdateDate.setText("" + (month + 1) + "/" + day + "/" + year);
             SimpleDateFormat sdf1 = new SimpleDateFormat("hh:mm: a");
             java.util.Date tt = new java.util.Date();
             String t = sdf1.format(tt);
             UpdateTime.setText(t);
         con=MySqlConnection.ConnectToDb();
         try
         {
             String Query="SELECT PRODUCTID FROM EXPNEWPOST WHERE EXPID='"+GetExpId+"' ORDER BY PRODUCTID ASC";
             pst=con.prepareStatement(Query);
            rs=pst.executeQuery(Query);
            while(rs.next())
            {
                DisplayProductDetailsToUpdate.addItem(rs.getString("PRODUCTID"));
            }
         }
         catch(Exception e)
         {
             JOptionPane.showMessageDialog(null, e);
         }
    }

   
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">                          
    private void initComponents() {

        MinimumQuantityDisplay = new javax.swing.JTextField();
        ProductNameDisplay = new javax.swing.JTextField();
        ProductIdDisplay = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        MaximumQuantityDisplay = new javax.swing.JTextField();
        PricePerPiece = new javax.swing.JTextField();
        jLabel7 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        UpdateDate = new javax.swing.JLabel();
        UpdateTime = new javax.swing.JLabel();
        Backbutton = new javax.swing.JButton();
        jLabel8 = new javax.swing.JLabel();
        ConfirmUpdateButton = new javax.swing.JButton();
        DisplayProductDetailsToUpdate = new javax.swing.JComboBox<>();
        jLabel1 = new javax.swing.JLabel();
        jLabel11 = new javax.swing.JLabel();
        jLabel9 = new javax.swing.JLabel();
        jMenuBar2 = new javax.swing.JMenuBar();
        DashboardButton = new javax.swing.JMenu();
        MyPosts = new javax.swing.JMenu();
        NewPost = new javax.swing.JMenu();
        MyWallet = new javax.swing.JMenu();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Foreign Trading System");

        MinimumQuantityDisplay.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N

        ProductNameDisplay.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        ProductNameDisplay.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ProductNameDisplayActionPerformed(evt);
            }
        });

        ProductIdDisplay.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        ProductIdDisplay.setText("");

        jLabel3.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        jLabel3.setText("ProductID:");

        jLabel4.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        jLabel4.setText("ProductName:");

        jLabel5.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        jLabel5.setText("MinimunQuantity:");

        jLabel6.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        jLabel6.setText("MaximumQuantity:");

        MaximumQuantityDisplay.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N

        PricePerPiece.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N

        jLabel7.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        jLabel7.setText("PricePiece:");

        jLabel2.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        jLabel2.setText("DATE:");

        UpdateDate.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        UpdateDate.setText("jLabel9");

        UpdateTime.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        UpdateTime.setText("jLabel10");

        Backbutton.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        Backbutton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/secure/back.JPG"))); // NOI18N
        Backbutton.setBorder(new javax.swing.border.SoftBevelBorder(javax.swing.border.BevelBorder.RAISED));
        Backbutton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                BackbuttonActionPerformed(evt);
            }
        });

        jLabel8.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        jLabel8.setText("TIME:");

        ConfirmUpdateButton.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        ConfirmUpdateButton.setIcon(new javax.swing.ImageIcon(getClass().getResource("/secure/wupdate.JPG"))); // NOI18N
        ConfirmUpdateButton.setBorder(new javax.swing.border.SoftBevelBorder(javax.swing.border.BevelBorder.RAISED));
        ConfirmUpdateButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ConfirmUpdateButtonActionPerformed(evt);
            }
        });

        DisplayProductDetailsToUpdate.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        DisplayProductDetailsToUpdate.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Choose" }));
        DisplayProductDetailsToUpdate.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                DisplayProductDetailsToUpdateActionPerformed(evt);
            }
        });

        jLabel1.setFont(new java.awt.Font("Comic Sans MS", 1, 14)); // NOI18N
        jLabel1.setText("Choose productId to Delete:");

        jLabel11.setIcon(new javax.swing.ImageIcon(getClass().getResource("/secure/fts8879.JPG"))); // NOI18N

        jLabel9.setIcon(new javax.swing.ImageIcon(getClass().getResource("/secure/updatepost.png"))); // NOI18N

        DashboardButton.setText("Dashboard");
        DashboardButton.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                DashboardButtonMouseClicked(evt);
            }
        });
        jMenuBar2.add(DashboardButton);

        MyPosts.setText("My Posts");
        MyPosts.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                MyPostsMouseClicked(evt);
            }
        });
        jMenuBar2.add(MyPosts);

        NewPost.setText("New Post");
        NewPost.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                NewPostMouseClicked(evt);
            }
        });
        jMenuBar2.add(NewPost);

        MyWallet.setText("My Wallet");
        MyWallet.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                MyWalletMouseClicked(evt);
            }
        });
        jMenuBar2.add(MyWallet);

        setJMenuBar(jMenuBar2);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap(499, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addComponent(jLabel9)
                        .addGap(359, 359, 359)
                        .addComponent(jLabel11, javax.swing.GroupLayout.PREFERRED_SIZE, 89, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(51, 51, 51))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                        .addComponent(jLabel6, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                        .addComponent(jLabel5, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                        .addComponent(jLabel4, javax.swing.GroupLayout.PREFERRED_SIZE, 127, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addComponent(jLabel7, javax.swing.GroupLayout.PREFERRED_SIZE, 125, javax.swing.GroupLayout.PREFERRED_SIZE))
                                    .addComponent(jLabel3, javax.swing.GroupLayout.PREFERRED_SIZE, 115, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(jLabel2)
                                    .addComponent(jLabel8))
                                .addGap(28, 28, 28)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                        .addComponent(PricePerPiece)
                                        .addComponent(MaximumQuantityDisplay)
                                        .addComponent(MinimumQuantityDisplay)
                                        .addComponent(ProductNameDisplay)
                                        .addComponent(UpdateDate, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                        .addComponent(ProductIdDisplay, javax.swing.GroupLayout.PREFERRED_SIZE, 328, javax.swing.GroupLayout.PREFERRED_SIZE))
                                    .addComponent(UpdateTime, javax.swing.GroupLayout.PREFERRED_SIZE, 333, javax.swing.GroupLayout.PREFERRED_SIZE)))
                            .addGroup(layout.createSequentialGroup()
                                .addGap(25, 25, 25)
                                .addComponent(ConfirmUpdateButton, javax.swing.GroupLayout.PREFERRED_SIZE, 119, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(109, 109, 109)
                                .addComponent(Backbutton, javax.swing.GroupLayout.PREFERRED_SIZE, 86, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(layout.createSequentialGroup()
                                .addGap(47, 47, 47)
                                .addComponent(DisplayProductDetailsToUpdate, javax.swing.GroupLayout.PREFERRED_SIZE, 236, javax.swing.GroupLayout.PREFERRED_SIZE)))
                        .addGap(357, 357, 357))))
            .addGroup(layout.createSequentialGroup()
                .addGap(421, 421, 421)
                .addComponent(jLabel1)
                .addGap(0, 0, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(42, 42, 42)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabel11)
                    .addComponent(jLabel9))
                .addGap(55, 55, 55)
                .addComponent(jLabel1)
                .addGap(18, 18, 18)
                .addComponent(DisplayProductDetailsToUpdate, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel3)
                    .addComponent(ProductIdDisplay))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(ProductNameDisplay, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel4))
                .addGap(11, 11, 11)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel5)
                    .addComponent(MinimumQuantityDisplay, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel6)
                    .addComponent(MaximumQuantityDisplay, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel7)
                    .addComponent(PricePerPiece, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel2)
                    .addComponent(UpdateDate))
                .addGap(26, 26, 26)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel8)
                    .addComponent(UpdateTime))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 8, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(ConfirmUpdateButton, javax.swing.GroupLayout.PREFERRED_SIZE, 52, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(Backbutton, javax.swing.GroupLayout.PREFERRED_SIZE, 51, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(59, 59, 59))
        );

        pack();
    }// </editor-fold>                        

    private void ProductNameDisplayActionPerformed(java.awt.event.ActionEvent evt) {                                                   
        // TODO add your handling code here:
    }                                                  

    private void DisplayProductDetailsToUpdateActionPerformed(java.awt.event.ActionEvent evt) {                                                              
        // TODO add your handling code here:
        
        SelectedItemToUpdate = DisplayProductDetailsToUpdate.getSelectedItem().toString();
        try
        {
            String Query="SELECT PRODUCTID,PRODUCTNAME,MINQTY,MAXQTY,PRICEPERPIECE FROM EXPNEWPOST WHERE PRODUCTID='"+ SelectedItemToUpdate+"' "; 
             pst=con.prepareStatement(Query);
            rs = pst.executeQuery(Query);
            while(rs.next())
            {
                ProductIdDisplay.setText(rs.getString("PRODUCTID"));
                ProductNameDisplay.setText(rs.getString("PRODUCTNAME"));
                MinimumQuantityDisplay.setText(rs.getString("MINQTY"));
                MaximumQuantityDisplay.setText(rs.getString("MAXQTY"));
                PricePerPiece.setText(rs.getString("PRICEPERPIECE"));
            }
        }
        catch(Exception e)
        {
            JOptionPane.showMessageDialog(null, e);
        }
        
        
    }                                                             

    private void ConfirmUpdateButtonActionPerformed(java.awt.event.ActionEvent evt) {                                                    
        // TODO add your handling code here:
        
        try
        {
            String ProductIdToUpdate = ProductIdDisplay.getText();
            String ProductNameToUpdate = ProductNameDisplay.getText();
            String MinumumQuantityToUpdate = MinimumQuantityDisplay.getText();
            String MaximumQuantityToUpdate = MaximumQuantityDisplay.getText();
            String PricePerPieceToUpdate = PricePerPiece.getText();
            java.util.Date date = new java.util.Date();
             java.sql.Date PostDate = new java.sql.Date(date.getTime());
             java.sql.Timestamp sqlTime=new java.sql.Timestamp(date.getTime());
            String Query1="UPDATE EXPNEWPOST set PRODUCTNAME='"+ProductNameToUpdate+"' ,MINQTY='"+MinumumQuantityToUpdate+"' ,MAXQTY='"+MaximumQuantityToUpdate+"' , PRICEPERPIECE='"+PricePerPieceToUpdate+"' ,DATE='"+PostDate+"' ,TIME='"+sqlTime+"' WHERE PRODUCTID='"+ProductIdToUpdate+"'";
            pst=con.prepareStatement(Query1);
            pst.execute();
            JOptionPane.showMessageDialog(null,"POST UPDATED");
            ExporterUpdatePost EDP =  new ExporterUpdatePost();
            EDP.setVisible(true);
            dispose();   
        }
        catch(Exception e)
        {
            JOptionPane.showMessageDialog(null, e);
        }
        
        
    }                                                   

    private void BackbuttonActionPerformed(java.awt.event.ActionEvent evt) {                                           
        // TODO add your handling code here:
          ExporterMyPosts EMP =  new ExporterMyPosts();
        EMP.setVisible(true);
        dispose();
        
    }                                          

    private void DashboardButtonMouseClicked(java.awt.event.MouseEvent evt) {                                             
        // TODO add your handling code here:
        ExporterDashboard ED = new ExporterDashboard();
        ED.setVisible(true);
        dispose();

    }                                            

    private void MyPostsMouseClicked(java.awt.event.MouseEvent evt) {                                     
        // TODO add your handling code here:
        ExporterMyPosts EMP = new ExporterMyPosts();
        EMP.setVisible(true);
        dispose();
    }                                    

    private void NewPostMouseClicked(java.awt.event.MouseEvent evt) {                                     
        // TODO add your handling code here:
        ExporterNewPost ENP = new ExporterNewPost();
        ENP.setVisible(true);
        dispose();
    }                                    

    private void MyWalletMouseClicked(java.awt.event.MouseEvent evt) {                                      
        // TODO add your handling code here:
        ExportersWallet EW = new ExportersWallet();
        EW.setVisible(true);
        dispose();
    }                                     

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(ExporterUpdatePost.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(ExporterUpdatePost.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(ExporterUpdatePost.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(ExporterUpdatePost.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new ExporterUpdatePost().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify                     
    private javax.swing.JButton Backbutton;
    private javax.swing.JButton ConfirmUpdateButton;
    private javax.swing.JMenu DashboardButton;
    private javax.swing.JComboBox<String> DisplayProductDetailsToUpdate;
    private javax.swing.JTextField MaximumQuantityDisplay;
    private javax.swing.JTextField MinimumQuantityDisplay;
    private javax.swing.JMenu MyPosts;
    private javax.swing.JMenu MyWallet;
    private javax.swing.JMenu NewPost;
    private javax.swing.JTextField PricePerPiece;
    private javax.swing.JLabel ProductIdDisplay;
    private javax.swing.JTextField ProductNameDisplay;
    private javax.swing.JLabel UpdateDate;
    private javax.swing.JLabel UpdateTime;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel11;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JMenuBar jMenuBar2;
    // End of variables declaration                   
}

