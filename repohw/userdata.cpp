#include "userdata.h"

using namespace std;

UserData::UserData(string id, string fn, string ln, string pn, string zip, string bt, string add)
{
	m_id = id;
	m_fname = fn;
	m_lname = ln;
	m_phone = pn;
	m_zip = zip;
	m_bloodtype = bt;
	m_add = add;
}

int UserData::compareFirstName(UserData& otherUD)
{
	return m_fname.compare(otherUD.m_fname);
}

int UserData::compareLastName(UserData& otherUD)
{
	return m_lname.compare(otherUD.m_lname);
}

int UserData::compareZip(UserData& otherUD)
{
	return m_zip.compare(otherUD.m_zip);
}

ostream& operator <<(ostream& os, UserData& ud)
{
	os << ud.m_id << ";" << ud.m_fname << ";" << ud.m_lname << ";" << ud.m_phone << ";" << ud.m_zip << ";" << ud.m_bloodtype << ";" << ud.m_add;
	return os;
}
