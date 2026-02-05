import sys
from PyQt6.QtWidgets import (
    QApplication, QWidget, QVBoxLayout,
    QHBoxLayout, QLineEdit, QPushButton,
    QListWidget, QMessageBox, QLabel
)
from PyQt6.QtCore import Qt

class TodoApp(QWidget):
    def __init__(self):
        super().__init__()

        # --- Window Configuration ---
        self.setWindowTitle("Task Management System (PyQt6)")
        self.setMinimumWidth(400)

        main_layout = QVBoxLayout()

        # Title
        title = QLabel("My Task List")
        title.setAlignment(Qt.AlignmentFlag.AlignCenter)
        main_layout.addWidget(title)

        # Task Input Field
        self.input = QLineEdit()
        self.input.setPlaceholderText("Enter a task...")
        main_layout.addWidget(self.input)

        # Buttons
        btn_layout = QHBoxLayout()

        self.add_btn = QPushButton("Add")
        self.del_btn = QPushButton("Delete Selected")
        self.clear_btn = QPushButton("Clear List")

        btn_layout.addWidget(self.add_btn)
        btn_layout.addWidget(self.del_btn)
        btn_layout.addWidget(self.clear_btn)

        main_layout.addLayout(btn_layout)

        # Task List Widget
        self.list_widget = QListWidget()
        main_layout.addWidget(self.list_widget)

        # Status Display
        self.status_label = QLabel("Tasks: 0")
        main_layout.addWidget(self.status_label)

        self.setLayout(main_layout)

        # Signal Connections
        self.add_btn.clicked.connect(self.add_task)
        self.del_btn.clicked.connect(self.delete_task)
        self.clear_btn.clicked.connect(self.clear_tasks)
        self.list_widget.itemSelectionChanged.connect(self.update_status)

    # --- Application Logic ---

    def add_task(self):
        text = self.input.text().strip()
        if not text:
            QMessageBox.warning(self, "Attention", "Please enter task description.")
            return
        self.list_widget.addItem(text)
        self.input.clear()
        self.update_status()

    def delete_task(self):
        item = self.list_widget.currentItem()
        if not item:
            QMessageBox.warning(self, "Attention", "Please select a task for deletion.")
            return
        row = self.list_widget.row(item)
        self.list_widget.takeItem(row)
        self.update_status()

    def clear_tasks(self):
        if self.list_widget.count() == 0:
            return

        reply = QMessageBox.question(
            self,
            "Confirmation",
            "Are you sure you want to delete all tasks?",
            QMessageBox.StandardButton.Yes | QMessageBox.StandardButton.No
        )

        if reply == QMessageBox.StandardButton.Yes:
            self.list_widget.clear()
            self.update_status()

    def update_status(self):
        count = self.list_widget.count()
        self.status_label.setText(f"Tasks: {count}")

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = TodoApp()
    window.show()
    sys.exit(app.exec())