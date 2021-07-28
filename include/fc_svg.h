#ifndef FC_SVG_H
#define FC_SVG_H

#include <string>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <sstream>

using namespace std;

/**
 * Insert in a string the content of a file
 * @param filename name of the file to read
 * @return string  the file content
*/
string fc_read_svg_device (string filename);

/**
 * Save in a file the svg epresentation of the device
 * @param svg_rep string with the svg representation of the structure to save
 * @return string with filename
*/
string fc_save(string svg_rep);

#endif