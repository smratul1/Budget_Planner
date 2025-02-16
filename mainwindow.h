#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QDateEdit>
#include <QLabel>
#include <QStatusBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMap>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddTransactionClicked();
    void calculateBudget();
    void saveData();
    void loadData();
    void onSearchTextChanged(const QString &text);
    void onFilterButtonClicked();
    void onManageCategoriesClicked();
    void onSetBudgetGoalClicked();
    void onClearButtonClicked();

private:
    QListWidget *transactionListWidget;
    QLabel *totalBudgetLabel;
    QStatusBar *statusBar;

    // UI elements
    QLineEdit *amountLineEdit;
    QComboBox *categoryComboBox;
    QDateEdit *dateEdit;
    QPushButton *addTransactionButton;
    QLineEdit *searchLineEdit;
    QPushButton *filterButton;
    QDateEdit *startDateEdit;
    QDateEdit *endDateEdit;
    QPushButton *clearButton;
    QPushButton *manageCategoriesButton;
    QPushButton *setBudgetGoalButton;

    // Common data
    double totalIncome;
    double totalExpenses;
    double totalBudget;
    QMap<QString, double> budgetGoals;

    void setupUI();
    void setupStatusBar();
    void filterTransactions();
    void loadCategories();
    void saveCategories();

    // Styles for UI elements
    QString getLineEditStyle();
    QString getComboBoxStyle();
    QString getDateEditStyle();
    QString getLabelStyle();
    QString getButtonStyle(const QString &color);
};

#endif
