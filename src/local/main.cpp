
/** TP 5ETI IMI- CPE Lyon - 2015-2016 */



#include "lib/common/error_handling.hpp"

#include "discrete/bresenham.hpp"
#include "discrete/line_discrete.hpp"
#include "discrete/line_interpolation_parameter.hpp"
#include "image/image.hpp"
#include "image/drawer.hpp"
#include "discrete/triangle_scanline.hpp"
#include "image/image_zbuffer.hpp"
#include "lib/mesh/mesh.hpp"
#include "lib/mesh/mesh_io.hpp"
#include "render_engine/render_engine.hpp"
#include "lib/3d/mat4.hpp"
#include "lib/3d/mat3.hpp"
#include "image/texture.hpp"

#include <iostream>
#include <fstream>
#include <cmath>



using namespace cpe;

int main(int argc,char *argv[])
{

    std::cout<<"***********************"<<std::endl;
    std::cout<<"run "<<argv[0]<<" with "<<argc-1<<" parameters ... \n"<<std::endl;


    try
    {
        int const Nx = 1024;
        int const Ny = 1024;

        image im(Nx,Ny);
        im.fill({1.0f,1.0f,1.0f});

        image_zbuffer zbuffer(Nx,Ny);

//        im(20,10) = color(1.0f,1.0f,0.0f);
//        im(21,10) = color(1.0f,0.0f,0.0f);

//        for(int k=0;k<20;++k)
//          {
//          im(10+k,5) = color(k/20.0f,0.0f,1.0f-k/20.0f);
//          im(19,5+k) = color(k/20.0f,k/20.0f,k/20.0f);
//          }


//        im.save("mon_image.ppm");

//        line_discrete line;        // creation d’une ligne discrete
//        line.push_back(ivec2(4,5));        // ajout d’une position
//        line.push_back({5,6});        // autre methode d’ajout
//        ivec2 const p(6,7);        // autre methode d’ajout
//        line.push_back(p);
//        std::cout<<line<<std::endl;        // affichage du contenu de la ligne
//        //premiere methode de parcours de la ligne
//        for(int k=0;k<line.size();++k)
//        std::cout<<line[k]<<" ";
//        std::cout<<std::endl;
//        //deuxieme methode de parcours de la ligne
//        for(ivec2 const& p : line)
//        std::cout<<p<<" ";
//        std::cout<<std::endl;

//        line_discrete line;
//        bresenham({5,5},{12,9},line);
//        std::cout<<line<<std::endl;


        //draw_line( im,{5,5},{1,12},color(1.0f,0.0f,0.0f),color(1.0f,1.0f,0.0f));

//        draw_triangle( im,zbuffer,{5,2},{1,15},{12,12},color(1.0f,1.0f,0.0f),color(1.0f,0.0f,0.0f),color(0.0f,1.0f,0.0f),0.0f,0.0f,1.0f);
//        draw_triangle( im,zbuffer,{8,5},{8,15},{1,7},color(0.0f,1.0f,0.0f),color(1.0f,0.0f,1.0f),color(0.0f,0.0f,1.0f),0.0f,0.0f,0.0f);

//        draw_triangle_wireframe(im , {15,12},{2,17},{6,3} , {0,0,0});
//        auto scanline = triangle_scanline_factory({15,12},{2,17},{6,3} ,
//        color(1,0,0),color(0,1,0),color(0,0,1));
//        std::cout<<scanline<<std::endl;


//        vec3 p0 = {-0.5,-0.5,-1.5};
//        vec3 p1 = {-0.5,0.5,-1.5};
//        vec3 p2 = {0.5,0.0,-4.0};

//        vec3 n0 = {0,0,1.0f};
//        vec3 n1 = {0,0,1.0f};
//        vec3 n2 = {0,0,1.0f};

//        color c0 = color(1.0f,1.0f,0.0f);
//        color c1 = color(1.0f,0.0f,0.0f);
//        color c2 = color(0.0f,1.0f,0.0f);

        mat4 model;
        mat4 view;
        mat4 projection;
        projection.set_projection_perspective(60*M_PI/180.0f,1.0f,0.1f,20.0f);

//        render(im,zbuffer,p0,p1,p2,c0,c1,c2,n0,n1,n2,model,view, projection);

//        im.save("mon_image.ppm");
        zbuffer.save("my_zbuffer.ppm");


//        line_discrete line;
//        bresenham({5,5},{12,9},line);
//        std::cout<<line<<std::endl;
//        line_interpolation_parameter interpolation(line);
//        std::cout<<interpolation<<std::endl;

    texture textureDino;
    textureDino.load("dino.ppm");


    mesh m = load_mesh_file("dino.obj");
    //applique potentiellement une rotation, translation
    //    (scaling possible egalement)
//    m.transform_apply_rotation({0,1,0},-M_PI/4.0f);
//    m.transform_apply_translation({0,0,-1.5f});
//    m.transform_apply_scale(0.5f);
//    m.fill_color({1,1,1}); //applique la couleur blanche a l’ensemble des sommets
    m.fill_normal(); //calcul automatique des normales

    mat3 rot;
    rot.set_rotation({0,1,0},-M_PI/4);
    model.set_transformation(rot,{0.0f,0,-1.5f});

    render( im, zbuffer, m, textureDino, model, view, projection);
    im.save("mon_image.ppm");
    }
    catch(cpe::exception_cpe const& e)
    {


        std::cout<<"**********************************"<<std::endl;
        std::cout<<"**********************************"<<std::endl;
        std::cout<<"Exception found"<<std::endl;
        std::cout<<e.info()<<std::endl;
        std::cout<<"\nSaving backtrace in file backtrace_log.txt"<<std::endl;
        std::cout<<"**********************************"<<std::endl;
        std::cout<<"**********************************"<<std::endl;


        std::ofstream back_file("backtrace_log.txt");
        back_file<<e.info()<<std::endl;
        back_file<<e.info_backtrace();
        back_file.close();

        exit(1);
    }


    std::cout<<"Exit Main"<<std::endl;

    return 0;
}
