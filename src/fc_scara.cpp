#include "fc_scara.h"

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

int* fc_ask_parameters(int p[7]){

    cout << "Enter a value for each parameter: " << endl;
    string inputValue;
    
    do {
    cout << "thickness: ";
    cin >> inputValue;
    } while(!is_number(inputValue));
    
    p[0] = stoi(inputValue);
    
    if (p[0] <= 0){
        return NULL;
    }
    cout << endl;

    do {
    cout << "length: ";
    cin >> inputValue;
    } while(!is_number(inputValue));
    
    p[1] = stoi(inputValue);

    if (4*p[0] >= p[1]|| p[1] <= 0 || p[1] > 200){
        return NULL;
    }
    cout << endl;

    do {
    cout << "radius: ";
    cin >> inputValue;
    } while(!is_number(inputValue));
    
    p[2] = stoi(inputValue);

    if (p[2] <= 0 || 2*p[2] > p[0]){
        return NULL;
    }
    cout << endl;

    do {
    cout << "q1: ";
    cin >> inputValue;
    } while(!is_number(inputValue));
    
    p[3] = stoi(inputValue);
    
    cout << endl;

    do {
    cout << "q2: ";
    cin >> inputValue;
    } while(!is_number(inputValue));
    
    p[4] = stoi(inputValue);
    
    if (p[4] == 180){
        return  NULL;   
    }
    cout << endl;

    do {
    cout << "x: ";
    cin >> inputValue;
    } while(!is_number(inputValue));
    
    p[5] = stoi(inputValue);
    cout << endl;

    do {
    cout << "y: ";
    cin >> inputValue;
    } while(!is_number(inputValue));
    
    p[6] = stoi(inputValue);
    cout << endl;

    //definition of the array of parameters

    return p;
    
}

fc_scara* fc_scara_init (int thickness,int length,int radius,int q1,int q2,int x,int y){
    
    if (thickness <= 0){
        return NULL;
    }
    else if (4*thickness >= length|| length <= 0 || length > 200){
        return NULL;
    }
    else if (radius <= 0 || 2*radius > thickness){
        return NULL;
    }
    else if (q2 == 180){
        return  NULL;   
    }
    else{
        /* 
        definition of a pointer to the struct scara 
        and initialization of a variable of type fc_scara with 
        dynamic memory allocation
            */
        fc_scara* robot = new fc_scara;

        robot -> thickness = thickness;
        robot -> length = length;
        robot -> radius = radius;
        robot -> q1 = q1;
        robot -> q2 = q2;
        robot -> origin.x = x;
        robot -> origin.y = y;
        robot -> svg_width = (length*2);

        return robot; // returning the pointer to the created structure

    }
}

string fc_scara_to_svg(fc_scara* scara){
    
       
    string scara_svg;
    //declaration of xml 
    scara_svg += "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?> \n";
    //svg namespace
    scara_svg += "<svg xmlns=\"http://www.w3.org/2000/svg\" width = \"" + to_string(scara -> svg_width + scara->origin.x) + "\" height = \"" + to_string(scara -> svg_width+scara->origin.y) + "\">\n";
    // creating a group of images
    scara_svg += "<g transform = \"rotate(" + to_string(scara->q1) + " " + to_string(scara->origin.x) + " " + to_string(scara->origin.y) + ") translate("+ to_string(scara->origin.x - scara->radius) + "," + to_string(scara->origin.y - (scara->thickness)/2)+")\" ";   
    // rectangle style
    scara_svg += "style =\" fill:rgb(128,128,128);stroke-width:3;stroke:rgb(0,0,0)\">\n";
    // drawing the first arm
    scara_svg += "<rect width = \"" + to_string(scara->length) + "\" height = \"" + to_string(scara->thickness)+ "\" />\n";
    //second arm
    scara_svg += "<rect width =\"" + to_string(scara->length) + "\" height =\"" + to_string(scara->thickness)+ "\" ";
    // translation to the position of the frame
    scara_svg += "transform = \"rotate(" + to_string(scara->q2)+ " " + to_string(scara->length - scara->radius) +" "+ to_string((scara->thickness)/2) + ") translate(" + to_string(scara->length  - 2* (scara->radius)) + "," + to_string(0)+ ")\"/>\n";
    // second revolute joint
    scara_svg += "<circle cx=\"" + to_string(scara->length - scara->radius) + "\" cy=\"" + to_string((scara->thickness)/2) + "\" r=\"" + to_string(scara->radius) + "\" stroke=\" black \" stroke-width=\"3\" fill=\" white \" /> \n";
    //end of the group
    scara_svg += "</g>\n";
    //first revolute joint
    scara_svg += "<circle cx= \"" + to_string(scara->origin.x) + "\" cy= \"" + to_string(scara->origin.y) + "\" r= \"" + to_string(scara->radius) + "\" stroke= \" black \" stroke-width=\"3\" fill=\" white \" /> \n";
    

    //end svg
    scara_svg.append("</svg>\n");

    return scara_svg;
   }

   int fc_set_thickness(fc_scara* robot){

       //set thickness
        int new_thickness;
        cout << "thickness: ";
        cin >> new_thickness;
        cout << endl;
                    
       if (new_thickness <= 0|| 4*new_thickness >= robot->length|| new_thickness <= (robot -> radius)*2){
           return 1;
       };
       robot -> thickness = new_thickness;
       return 0;
   }

   int fc_set_length(fc_scara* robot){

        int new_length;
        cout << "length: ";
        cin >> new_length;
        cout << endl;

       if (new_length > 200 || new_length <= 0){
           return 1;
       };

       robot -> length = new_length;
       return 0;
   }

   int fc_set_radius(fc_scara* robot){

        int new_radius;
        cout << "radius: ";
        cin >> new_radius;
        cout << endl;

       if (2 * new_radius > (robot -> thickness) || new_radius <= 0){
           return 1;
       };

       robot-> radius = new_radius;
       return 0;
   }

   int fc_set_q1(fc_scara* robot){
        
        int new_q1;
        cout << "q1: ";
        cin >> new_q1;
        cout << endl;

       robot-> q1 = new_q1;
       return 0;
   }

   int fc_set_q2(fc_scara* robot){

        int new_q2;
        cout << "q2: ";
        cin >> new_q2;
        cout << endl;

       if (new_q2 == 180){
           return 1;
       }
       robot-> q2 = new_q2;
       return 0;
   }



   int fc_set_frame(fc_scara* robot){
       int new_x;
       int new_y;

       cout << "x: ";
       cin >> new_x;
       cout << endl;

       cout << "y: ";
       cin >> new_y;
       cout << endl;
       
       if(new_x < 0 || new_y < 0){
           return 1;
       };

       robot -> origin.x = new_x;
       robot -> origin.y = new_y;

       return 0;
   }

   
/*
   fc_scara* fc_read_svg_device(string filename){
    // definition of an object called svg
    ifstream svg(filename + ".svg");
    

    
    if (!svg.good()) {
    cout << "from_svg: File does not exist" << endl;
    return NULL;
    }
    
    // definition of a string in which 
    string line = "";
    
    // use isopen method in if because it returns a bool
    if(svg.is_open()){
        //using a while loop to iterate 
        while(getline(svg, line)){
            size_t index = 0;

            if 

        }

    }

    fc_scara* fc_scara_init


    ifstream t(filename);

    stringstream buffer;
    
    buffer << t.rdbuf();
    
    string s = buffer.str();
    
    cout << "the file " << filename << "has been read" << endl;
    
    return s;

}
*/
    fc_scara* fc_svg_to_scara(string content){
    /*
        this function could be implemented in a better way by intriducing some kind of iteration
    */
    // improvement: instead of "= \"" you could search just "\"" -> try

    // some auxiliary strings
    string rotation = "= \"r";
    string space = " ";
    string svg_head = "<g";
    size_t r = strlen("rotate(");
    
    //auxiliary string
    string aux;

    // parameters from transformation of the svg file
    string p = "= \""; // every instruction in the svg starts with this sequence of chars
    size_t found = content.find(svg_head); // skip declaration of svg file
    size_t found1 = content.find(p,found); // find the first occurence in the file of string p startin from group definition <g
    size_t found2 = content.find("\"", found1+3); // find the first occurence of rottion directive
    size_t found3 = content.find(" ", found1 +3); // find the first space starting from found1
    
    string check_str = content.substr(found1, 4);
    
    aux = content.substr(found1 +3, found2 - found1 - 3 ); // maybe this line could be deleted

    // extracting q1
    string aux1 = content.substr(found1 + 3 + r, found3 - found1 -3 -r);
    int q1 = stoi(aux1);
    cout <<"q1: " <<q1 << endl;

    //extracting length
    found1 = content.find(p, found2);
    found2 = content.find("\"", found1+3);
    aux = content.substr(found1 +3, found2 - found1 - 3 );  
    cout << "length: " << aux << endl;
    int length = stoi(aux);

    //extracting thickness
    found1 = content.find(p, found2);
    found2 = content.find("\"", found1+3);
    aux = content.substr(found1 +3, found2 - found1 - 3 );
    cout << "thickness: " << aux << endl;
    int thickness = stoi(aux);

    //extracting q2
    found1 = content.find(p, found2);
    found2 = content.find("\"", found1+3);
    aux1 = content.substr(found1 + 3 + r, found3 - found1 -3 -r);
    int q2 = stoi(aux1);
    cout <<"q2: " <<q2 << endl;

    //extracting frame x coordinate
    found1 = content.find(p, found2);
    found2 = content.find("\"", found1+3);
    aux = content.substr(found1 +3, found2 - found1 - 3 );
    cout << "x_coordinate: " << aux << endl;
    int xc = stoi(aux);

    //extracting frame y coordinate
    found1 = content.find(p, found2);
    found2 = content.find("\"", found1+3);
    aux = content.substr(found1 +3, found2 - found1 - 3 );
    cout << "y_coordinate: " << aux << endl;
    int yc = stoi(aux);
    
    //extracting radius
    found1 = content.find(p, found2);
    found2 = content.find("\"", found1+3);
    aux = content.substr(found1 +3, found2 - found1 - 3 );
    cout << "radius: " << aux << endl;
    int radius = stoi(aux);

    //initializing a new struct

    fc_scara* scara = fc_scara_init(thickness,length,radius,q1,q2,xc,yc);

    return scara;
}
// maybe implement a function which overwrite to a file using the .replace() method? //


void fc_delete_robot(fc_scara* robot){
    delete robot;
}

fc_scara* fc_load_from_file(string filename){
    
    string content = fc_read_svg_device(filename);

    fc_scara* scara = fc_svg_to_scara(content);

    return scara;
}

string fc_scara_save(fc_scara* scara){

    string s = fc_scara_to_svg(scara);

    return fc_save(s);

}
