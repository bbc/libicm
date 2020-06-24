#include <string>
#include <memory>
#include <vector>
#include <stdio.h>
#include "icm2html.hpp"

#ifndef IVSELEMENTS_HPP
#define IVSELEMENTS_HPP

namespace icm_html_cpp{

enum IVS_ELEMENT_TYPE{
    IVS_GAIN,
    IVS_ONOFF,
    IVS_COMP_OBJECT,
    IVS_POSITION
};

class IVSElement{
    public:
        IVSElement(IVS_ELEMENT_TYPE element_type);
        ~IVSElement();
        IVS_ELEMENT_TYPE m_element_type;

};

class IVSGainElement : IVSElement {
    public:
        IVSGainElement(std::shared_ptr<adm::AudioObject> the_obj, float gain_val);
        std::shared_ptr<adm::AudioObject> m_obj;
        float m_val;
};

class IVSOnOffElement : IVSElement{
    public:
        IVSOnOffElement(std::shared_ptr<adm::AudioObject> the_obj, bool is_on);
        std::shared_ptr<adm::AudioObject> m_obj;
        bool m_is_on;

};

class IVSPosElement : IVSElement {
    public:
        IVSPosElement(std::shared_ptr<adm::AudioObject> the_obj, bool is_polar, float x_or_azimuth = 0, float y_or_elevation = 0, float z_or_distance = 0);
        std::shared_ptr<adm::AudioObject> m_obj;
        bool m_is_polar;
        float m_x_or_azimuth;
        float m_y_or_elevation;
        float m_z_or_distance;

};

class IVSComplementaryAudioElement : IVSElement {
    public:
        IVSComplementaryAudioElement(std::shared_ptr<adm::AudioObject> the_obj, std::shared_ptr<adm::AudioObject> comp_obj);
        std::shared_ptr<adm::AudioObject> m_obj;
        std::shared_ptr<adm::AudioObject> m_comp_obj;
};


}

#endif