#include "MurderMystery.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

Menu::Menu()
{
    gamePlay();
}

void Menu :: gamePlay()
{
    cs.setCharacters();
    int life=0, suspectNum, weaponNum;
    bool solved;

    c1=c1.main_menu_case(c1);
}

Case Case::main_menu_case(Case g)
{
	string weapon1 = "Dagger";
	string weapon2 = "Lead Pipe";
	string weapon3 = "Rope";
	string weapon4 = "Candle Stick";
	string weapon5 = "Wrench";

	g.setWeapon(weapon1);
	g.setWeapon(weapon2);
	g.setWeapon(weapon3);
	g.setWeapon(weapon4);
	g.setWeapon(weapon5);

	string clue1 = "Clue 1: The deceased has an open wound.\n";
	string clue2 = "Clue 2: As a farmer, Johnny Tightlips is physically build. A toolbox was found in his vehicle\n";
	string clue3 = "Clue 3: Small traces of blood found on Joey Calabrese shirt cuffs.\n";
	string clue4 = "Clue 4: A receipt from a hardware store was found in Frankie Squealer's car.\nThe receipt indicates that he bought a sharpening stone.\n";
	string clue5 = "Clue 5: Small traces of wax was found on Bridgette Gotti hands.\n";

	g.setClue(clue1);
	g.setClue(clue2);
	g.setClue(clue3);
	g.setClue(clue4);
	g.setClue(clue5);

	return g;
}

void Case :: setClue(string clue)
{
    clues.push_back(clue);
}
void Case :: setWeapon(string weapon)
{
    weaponList.push_back(weapon);
}

void Case :: setSolved(bool solved)
{
    this->solved = solved;
}
string Case :: getClue(int clueNum)
{
    return clues[clueNum];
}

string CaseStory :: getHowToPlay()
{
    ifstream instructions("instructions.txt");
    string line;
    string ret;

    cout<<"\n\n"<<endl;

    if(!instructions.is_open())
    {
        cout<<"Can't open file"<<endl;
        exit(1);
    }
    while(!instructions.eof())
    {
        getline(instructions, line);
        ret=ret+line+"\n\n";
    }
    return ret;
}

void CaseStory :: setCharacters()
{
  Person Bridgette("Bridgette Gotti");
  Person Dan("Dan Gillick");
	Person Johnny("Johnny Tightlips");
	Person Frank("Frankie Squealer");
	Person Joey("Joey Calabrese");

	Dan.setMurderer(false);
	Johnny.setMurderer(false);
	Joey.setMurderer(false);
	Frank.setMurderer(true);
	Bridgette.setMurderer(false);

	characters.push_back(Bridgette);
  characters.push_back(Dan);
  characters.push_back(Johnny);
  characters.push_back(Frank);
  characters.push_back(Joey);
}

Person CaseStory :: getCharacter(int characterNum)
{
    return characters[characterNum-1];
}

Person::Person(string name)
{
    this->name=name;
}

void Person :: setMurderer(bool guilty)
{
    murderer = guilty;
}

bool Person :: getMurderer()
{
    return murderer;
}
string Person :: getName()
{
    return name;
}

SuspectWindow::SuspectWindow(Menu m) : box(Gtk::ORIENTATION_VERTICAL)
{
    set_size_request(600,600);
    set_position(Gtk::WIN_POS_CENTER);
    Gtk::Frame Frame_LineWrapped;

    label.set_text(m.c1.getClue(0));
    box.pack_start(label,0,0);

    label2.set_text(m.c1.getClue(1));
    box.pack_start(label2,0,0);

    label3.set_text(m.c1.getClue(2));
    box.pack_start(label3);

    label4.set_text(m.c1.getClue(3));
    box.pack_start(label4);

    label5.set_text(m.c1.getClue(4));
    box.pack_start(label5);

    s_label.set_text("\n");
    box.pack_start(s_label);

    set_border_width(10);

    add(box);

    Alibi.set_text("Click to see Alibi's");
    box.pack_start(Alibi);

    ab1.add_label(m.cs.getCharacter(1).getName());
    ab1.set_size_request(80,32);
    hbox.pack_start(ab1);
    ab1.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::ab1_clicked));

    ab2.add_label(m.cs.getCharacter(2).getName());
    ab2.set_size_request(80,32);
    hbox.pack_start(ab2);
    ab2.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::ab2_clicked));

    ab3.add_label(m.cs.getCharacter(3).getName());
    ab3.set_size_request(80,32);
    hbox.pack_start(ab3);
    ab3.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::ab3_clicked));

    ab4.add_label(m.cs.getCharacter(4).getName());
    ab4.set_size_request(80,32);
    hbox.pack_start(ab4);
    ab4.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::ab4_clicked));

    ab5.add_label(m.cs.getCharacter(5).getName());
    ab5.set_size_request(80,32);
    hbox.pack_start(ab5);
    ab5.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::ab5_clicked));

    box.pack_start(hbox);

    label_space.set_text("\n");
    box.pack_start(label_space);

    suspect.set("Suspect.png");
    box.pack_start(suspect);

    s1.add_label(m.cs.getCharacter(1).getName());
    s1.set_size_request(80,32);
    sGrid.attach(s1,0,0,1,5);
    s1.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedNotMurder));

    s2.add_label(m.cs.getCharacter(2).getName());
    s2.set_size_request(80,32);
    sGrid.attach(s2,1,0,1,5);
    s2.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedNotMurder));

    s3.add_label(m.cs.getCharacter(3).getName());
    s3.set_size_request(80,32);
    sGrid.attach(s3,2,0,1,5);
    s3.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedNotMurder));

    s4.add_label(m.cs.getCharacter(4).getName());
    s4.set_size_request(80,32);
    sGrid.attach(s4,3,0,1,5);
    s4.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedMurder));

    s5.add_label(m.cs.getCharacter(5).getName());
    s5.set_size_request(80,32);
    sGrid.attach(s5,4,0,1,5);
    s5.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedNotMurder));

    box.pack_start(sGrid);
    show_all_children();

};

SuspectWindow::~SuspectWindow(){}

void SuspectWindow :: ab1_clicked()
{
    Gtk::MessageDialog dialog(*this, "Bridgette Gotti's Alibi", false, Gtk::MESSAGE_INFO);
    dialog.set_secondary_text("I think Joey did it.\nI saw her last time talking to Joey downstairs about something.\nI was in my office writing up Joey's insurance risk documents until I heard a scream.");
    dialog.run();
}

void SuspectWindow :: ab2_clicked()
{
    Gtk::MessageDialog dialog(*this, "Dan Gillick's Alibi", false, Gtk::MESSAGE_INFO);
    dialog.set_secondary_text("I was seeing a basketball game in the city at that time.\nI only met her once and I think Johnny Tightlips was there after I finished up my shift.");
    dialog.run();
}

void SuspectWindow :: ab3_clicked()
{
    Gtk::MessageDialog dialog(*this, "Johnny Tightlips's Alibi", false, Gtk::MESSAGE_INFO);
    dialog.set_secondary_text("There are three sides to every story.\nMine, yours, and the truth.\n\"I ain't sayin' nothing'!\"");
    dialog.run();
}

void SuspectWindow :: ab4_clicked()
{
    Gtk::MessageDialog dialog(*this, "Frankie Squealer's Alibi", false, Gtk::MESSAGE_INFO);
    dialog.set_secondary_text("I think Dan did it. He told me he had taken an interest in her about dating.\nI'm pretty sure the last time I saw her, they were talking at the bottom of the stairs.");
    dialog.run();
}

void SuspectWindow :: ab5_clicked()
{
    Gtk::MessageDialog dialog(*this, "Joey Calabrese's Alibi", false, Gtk::MESSAGE_INFO);
    dialog.set_secondary_text("I was present there at the time.\nI heard a knife sharpening sound and then I heard a scream.");
    dialog.run();
}

void SuspectWindow::onButtonClickedMurder()
{
    weapons.set("Weapon.jpg");
    hello2.pack_start(weapons);
    box.pack_start(hello2);

    w1.add_label("Dagger");
    wGrid.attach(w1,0,0,1,5);
    w1.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedWeapon));

    w2.add_label("Lead Pipe");
    wGrid.attach(w2,1,0,1,5);
    w2.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedMurderNotWeapon));

    w3.add_label("Rope");
    wGrid.attach(w3,2,0,1,5);
    w3.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedMurderNotWeapon));

    w4.add_label("Candle Stick");
    wGrid.attach(w4,3,0,1,5);
    w4.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedMurderNotWeapon));

    w5.add_label("Wrench");
    wGrid.attach(w5,4,0,1,5);
    w5.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedMurderNotWeapon));

    box.pack_start(wGrid);
    show_all_children();
}

void SuspectWindow::onButtonClickedNotMurder()
{
    weapons.set("Weapon.jpg");
    hello2.pack_start(weapons);
    box.pack_start(hello2);

    w1.add_label("Dagger");
    wGrid.attach(w1,0,0,1,5);
    w1.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedNotMurderWeapon));

    w2.add_label("Lead Pipe");
    wGrid.attach(w2,1,0,1,5);
    w2.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedNotWeapon));

    w3.add_label("Rope");
    wGrid.attach(w3,2,0,1,5);
    w3.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedNotWeapon));

    w4.add_label("Candle Stick");
    wGrid.attach(w4,3,0,1,5);
    w4.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedNotWeapon));

    w5.add_label("Wrench");
    wGrid.attach(w5,4,0,1,5);
    w5.signal_clicked().connect(sigc::mem_fun(*this, &SuspectWindow::onButtonClickedNotWeapon));

    box.pack_start(wGrid);
    show_all_children();

}

void SuspectWindow::onButtonClickedWeapon()
{
    solved=true;

    hide();
}
void SuspectWindow::onButtonClickedNotWeapon()
{
    close();
}

void SuspectWindow::onButtonClickedMurderNotWeapon()
{
    Gtk::MessageDialog dialog(*this, "NOT SOLVED!", false, Gtk::MESSAGE_INFO);
    dialog.set_secondary_text("Right Murderer, Wrong Weapon");
    dialog.run();

    close();
}
void SuspectWindow::onButtonClickedNotMurderWeapon()
{
    Gtk::MessageDialog dialog(*this, "NOT SOLVED!", false, Gtk::MESSAGE_INFO);
    dialog.set_secondary_text("Wrong Murderer, Right Weapon");
    dialog.run();

    close();
}


welcome_window::welcome_window()
{
    image.set("image.jpg");
    image2.set("play1.png");
    image3.set("cancel.png");

    resize(800,600);
    set_border_width(10);
    set_position(Gtk::WIN_POS_CENTER);

    set_title("Murder Mystery");

    play1.set_size_request(80, 32);
    play1.set_image(image2);
    play1.signal_clicked().connect(sigc::mem_fun(*this,&welcome_window::PlaySignal));

    exit1.set_size_request(80,32);
    exit1.set_image(image3);
    exit1.signal_clicked().connect(sigc::mem_fun(*this,&welcome_window::ExitSignal));

    hbox.pack_start(play1,1,0);
    hbox2.pack_start(exit1,1,0);

    vbox.pack_start(image);
    vbox.pack_start(grid);
    vbox.pack_start(hbox);
    vbox.pack_start(hbox2);
    box.pack_start(vbox);

    add(box);

    show_all_children();
}
welcome_window::~welcome_window(){}

void welcome_window::PlaySignal()
{
    hide();

}
void welcome_window::ExitSignal()
{
    exit(0);
}

Background_Window::Background_Window(): box(Gtk::ORIENTATION_VERTICAL)
{
    resize(100,100);
    this->set_border_width(60);
    set_title("Background Information");
    set_position(Gtk::WIN_POS_CENTER);

    add(box);
    Gtk::Frame Frame_LineWrapped;

    label.set_text("Scene Incident Report:\n\nYou arrive at the crime scene (1400 hours) on 123 Bourbon Street.\n\nAt 1200 hours, the complaintant, Bridgette Gotti, contacted the 911 operator and requested immediate medical assistance\nupon the discovery of a deceased individual inside her employers' household.\n\nUpon arrival at the crime scene, the homicide unit has detained five suspects, including Ms. Gotti, for interrogation.\n\nAt 1700 hours, the homicide unit has obtained evidence and clues at the crime scene.\n\nAt 2100 hours, interrogation of the five suspects were completed.\n\n");
    box.pack_start(label);

    back_image.set("location.png");
    box.pack_start(back_image);

    label1.set_text("\n");
    box.pack_start(label1);

    continue_button.add_label("Continue");
    continue_button.signal_clicked().connect(sigc::mem_fun(*this,&Background_Window::background_continue));
    box.pack_start(continue_button);

    show_all_children();
}

Background_Window::~Background_Window(){}

void Background_Window::background_continue()
{
    hide();
}


Exit_Correct::Exit_Correct(): solved_box(Gtk::ORIENTATION_VERTICAL)
{
    set_size_request(100,100);
    this->set_border_width(60);
    set_title("Exit Page");
    set_position(Gtk::WIN_POS_CENTER);

    add(solved_box);

    solved_label.set_text("\nCongratulations! You caught the murderer!\n");
    solved_box.pack_start(solved_label);

    solved_image.set("solved.jpg");
    solved_box.pack_start(solved_image);

    label.set_text("\n");
    solved_box.pack_start(label);

    home_button.add_label("Continue to Home Menu");
    home_button.signal_clicked().connect(sigc::mem_fun(*this,&Exit_Correct::home_page));
    solved_box.pack_start(home_button);

    show_all_children();
}

Exit_Correct::~Exit_Correct(){}

void Exit_Correct::home_page()
{
    hide();
}


Exit_Incorrect::Exit_Incorrect(): unsolved_box(Gtk::ORIENTATION_VERTICAL)
{
    set_size_request(100,100);
    this->set_border_width(60);
    set_title("Exit Page");
    set_position(Gtk::WIN_POS_CENTER);

    add(unsolved_box);

    unsolved_label.set_text("\nSorry! You didn't choose the correct murderer and weapon. This case remains unsolved.\n");
    unsolved_box.pack_start(unsolved_label);

    unsolved_image.set("unsolved.jpg");
    unsolved_box.pack_start(unsolved_image);

    label.set_text("\n");
    unsolved_box.pack_start(label);

    home_button.add_label("Continue to Home Menu");
    home_button.signal_clicked().connect(sigc::mem_fun(*this,&Exit_Incorrect::home_page));
    unsolved_box.pack_start(home_button);

    show_all_children();
}

Exit_Incorrect::~Exit_Incorrect()
{

}

void Exit_Incorrect::home_page()
{
    hide();
}

Rules::Rules(Menu m)
: m_VBox2(Gtk::ORIENTATION_VERTICAL, 5), m_Frame_LineWrapped("***GAME RULES***")
, button_send("Continue")
{
    set_size_request(700, 200);
    set_title("Mystery Murder Game");
    set_border_width(5);
    set_position(Gtk::WIN_POS_CENTER);

    image.set("McGruff.png");
    m_HBox.pack_start(image);

    add(m_HBox);

    m_HBox.pack_start(m_VBox2, Gtk::PACK_SHRINK);

    m_Label_LineWrapped.set_text(m.cs.getHowToPlay());
    m_Label_LineWrapped.set_line_wrap();
    m_Frame_LineWrapped.add(m_Label_LineWrapped);
    m_VBox2.pack_start(m_Frame_LineWrapped, Gtk::PACK_SHRINK);

    label_space.set_text("\n");
    m_VBox2.pack_start(label_space);

    button_send.signal_clicked().connect(sigc::mem_fun(*this,
    &Rules::send_value));
    m_VBox2.pack_start(button_send);

    show_all_children();
}

Rules::~Rules()
{
}

void	Rules::send_value()
{
    hide();
    Background_Window story;
    Gtk::Main::run(story);
}

Loop :: Loop(Gtk::Main app)
{
    while(true){
        Menu m1;

        int life=0;
        bool s=false;

        welcome_window wind;
        Gtk::Main::run(wind);

        Rules rules(m1);
        Gtk::Main::run(rules);

        SuspectWindow window(m1);
        Gtk::Main::run(window);

        s=window.solved;
        life++;

        if(life<3 && !s)
        {
            SuspectWindow win(m1);
            Gtk::Main::run(win);

            s=win.solved;
            life++;
        }

        if(life<3 && !s)
        {
            SuspectWindow w(m1);
            Gtk::Main::run(w);

            s=w.solved;
            life++;
        }

        if(s)
        {
            Exit_Correct e1;
            Gtk::Main::run(e1);
        }
        else
        {
            Exit_Incorrect e;
            Gtk::Main::run(e);
        }
    }
}
Loop :: ~Loop(){}
