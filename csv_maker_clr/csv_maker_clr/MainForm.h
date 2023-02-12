#pragma once
#include<string>
#include"dirent.h"

namespace csvmaker
{
	void maketxt()
	{
		DIR *d;
    	FILE *fp;
    	errno_t err;
    	struct dirent *dir;

    	// open the file for writing
    	err = fopen_s( &fp, "add_to_mod_csv.txt", "w" );

    	if( fp == NULL )
    	{
    	    //printf( "Error opening the file add_to_mod_csv.txt" );
    	    return;
    	}
// **write materials in file**
    	d = opendir( "./materials" );

    	if( d )
    	{
        	while( ( dir = readdir( d ) ) != NULL )
        	{
        	    if( ( strcmp( dir->d_name, "." ) == 0 ) || ( strcmp( dir->d_name, ".." ) == 0 ) )
        	        continue;
        	    fprintf( fp, "material,%s\n", dir->d_name );
        	}
// **write xmodels in file**
        	d = opendir( "./xmodel" );
        	if( d )
        	{
        	    while( ( dir = readdir( d ) ) != NULL )
        	    {
        	        if( ( strcmp( dir->d_name, "." ) == 0 ) || ( strcmp( dir->d_name, ".." ) == 0 ) )
        	            continue;
        	        fprintf( fp, "xmodel,%s\n", dir->d_name );
        	    }
        	}
// **write xanims in file**
        	d = opendir( "./xanim" );
        	if( d )
        	{
        	    while( ( dir = readdir( d ) ) != NULL )
        	    {
        	        if( ( strcmp( dir->d_name, "." ) == 0 ) || ( strcmp( dir->d_name, ".." ) == 0 ) )
        	            continue;
        	        fprintf( fp, "xanim,%s\n", dir->d_name );
        	    }
        	}
        	// close the file
        	fclose( fp );
        	closedir( d );
    	}
    }

    void makecsv()
	{
		DIR *d;
    	FILE *fp;
    	errno_t err;
    	struct dirent *dir;

    	// open the file for writing
    	err = fopen_s( &fp, "mod.csv", "w" );

    	if( fp == NULL )
    	{
    	    //printf( "Error opening the file mod.csv" );
    	    return;
    	}
// **write materials in file**
    	d = opendir( "./materials" );

    	if( d )
    	{
        	while( ( dir = readdir( d ) ) != NULL )
        	{
        	    if( ( strcmp( dir->d_name, "." ) == 0 ) || ( strcmp( dir->d_name, ".." ) == 0 ) )
        	        continue;
        	    fprintf( fp, "material,%s\n", dir->d_name );
        	}
// **write xmodels in file**
        	d = opendir( "./xmodel" );
        	if( d )
        	{
        	    while( ( dir = readdir( d ) ) != NULL )
        	    {
        	        if( ( strcmp( dir->d_name, "." ) == 0 ) || ( strcmp( dir->d_name, ".." ) == 0 ) )
        	            continue;
        	        fprintf( fp, "xmodel,%s\n", dir->d_name );
        	    }
        	}
// **write xanims in file**
        	d = opendir( "./xanim" );
        	if( d )
        	{
        	    while( ( dir = readdir( d ) ) != NULL )
        	    {
        	        if( ( strcmp( dir->d_name, "." ) == 0 ) || ( strcmp( dir->d_name, ".." ) == 0 ) )
        	            continue;
        	        fprintf( fp, "xanim,%s\n", dir->d_name );
        	    }
        	}
        	// close the file
        	fclose( fp );
        	closedir( d );
    	}
    }
}

namespace csvmakerclr {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace csvmaker;
	using namespace System::IO;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
    private: System::Windows::Forms::Label^ pathname;
    protected:

	protected:
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ btnGencsv;
	private: System::Windows::Forms::Button^ btnGentxt;
    private: System::Windows::Forms::Label^ lbGenloc;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
            this->pathname = (gcnew System::Windows::Forms::Label());
            this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->btnGencsv = (gcnew System::Windows::Forms::Button());
            this->btnGentxt = (gcnew System::Windows::Forms::Button());
            this->lbGenloc = (gcnew System::Windows::Forms::Label());
            this->tableLayoutPanel1->SuspendLayout();
            this->SuspendLayout();
            // 
            // pathname
            // 
            this->pathname->AutoSize = true;
            this->pathname->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->pathname->Location = System::Drawing::Point(12, 9);
            this->pathname->Name = L"pathname";
            this->pathname->Size = System::Drawing::Size(110, 19);
            this->pathname->TabIndex = 0;
            this->pathname->Text = L"File created to:";
            this->pathname->Click += gcnew System::EventHandler(this, &MainForm::currf_Click);
            // 
            // tableLayoutPanel1
            // 
            this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->tableLayoutPanel1->ColumnCount = 2;
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
                50)));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
                266)));
            this->tableLayoutPanel1->Controls->Add(this->btnGencsv, 0, 0);
            this->tableLayoutPanel1->Controls->Add(this->btnGentxt, 1, 0);
            this->tableLayoutPanel1->Location = System::Drawing::Point(16, 245);
            this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
            this->tableLayoutPanel1->RowCount = 1;
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
            this->tableLayoutPanel1->Size = System::Drawing::Size(526, 47);
            this->tableLayoutPanel1->TabIndex = 1;
            // 
            // btnGencsv
            // 
            this->btnGencsv->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->btnGencsv->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnGencsv->Location = System::Drawing::Point(3, 3);
            this->btnGencsv->Name = L"btnGencsv";
            this->btnGencsv->Size = System::Drawing::Size(254, 31);
            this->btnGencsv->TabIndex = 0;
            this->btnGencsv->Text = L"Generate csv";
            this->btnGencsv->UseVisualStyleBackColor = true;
            this->btnGencsv->Click += gcnew System::EventHandler(this, &MainForm::btnGencsv_Click);
            // 
            // btnGentxt
            // 
            this->btnGentxt->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->btnGentxt->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnGentxt->Location = System::Drawing::Point(263, 3);
            this->btnGentxt->Name = L"btnGentxt";
            this->btnGentxt->Size = System::Drawing::Size(260, 31);
            this->btnGentxt->TabIndex = 1;
            this->btnGentxt->Text = L"Generate txt";
            this->btnGentxt->UseVisualStyleBackColor = true;
            this->btnGentxt->Click += gcnew System::EventHandler(this, &MainForm::btnGentxt_Click);
            // 
            // lbGenloc | Location where generated the file.
            // 
            this->lbGenloc->AutoSize = true;
            this->lbGenloc->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbGenloc->Location = System::Drawing::Point(12, 46);
            this->lbGenloc->Name = L"lbGenloc";
            this->lbGenloc->Size = System::Drawing::Size(45, 19);
            this->lbGenloc->TabIndex = 2;
            this->lbGenloc->Text = L"label1";
            this->lbGenloc->Click += gcnew System::EventHandler(this, &MainForm::lbCurrfile_Click);
            // 
            // MainForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)));
            this->ClientSize = System::Drawing::Size(554, 304);
            this->Controls->Add(this->lbGenloc);
            this->Controls->Add(this->tableLayoutPanel1);
            this->Controls->Add(this->pathname);
            this->MinimumSize = System::Drawing::Size(570, 200);
            this->Name = L"MainForm";
            this->Text = L"csv maker";
            this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
            this->tableLayoutPanel1->ResumeLayout(false);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
	private: System::Void btnGencsv_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		csvmaker::makecsv();
		String^ label1 = this->lbGenloc->Text;
		String^ fileName = "\\mod.csv";
		String^ path = ".";
		String^ fullPath;
		fullPath = Path::GetFullPath( path );
		String^ res = fullPath + fileName;

		this->lbGenloc->Text = res;
	}
	private: System::Void btnGentxt_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		csvmaker::maketxt();

		String^ fileName = "\\add_to_mod_csv.txt";
		String^ path = ".";
		String^ fullPath;
		fullPath = Path::GetFullPath( path );
		String^ res = fullPath + fileName;

		this->lbGenloc->Text = res;
	}
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		this->lbGenloc->Text = "";
	}
	private: System::Void lbCurrfile_Click(System::Object^ sender, System::EventArgs^ e) 
	{
	}
	private: System::Void currf_Click(System::Object^ sender, System::EventArgs^ e) 
	{
	}
};
}
