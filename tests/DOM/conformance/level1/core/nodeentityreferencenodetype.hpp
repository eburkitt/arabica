
/*
This c++ source file was generated by for Arabica
and is a derived work from the source document.
The source document contained the following notice:


Copyright (c) 2001-2004 World Wide Web Consortium,
(Massachusetts Institute of Technology, Institut National de
Recherche en Informatique et en Automatique, Keio University). All
Rights Reserved. This program is distributed under the W3C's Software
Intellectual Property License. This program is distributed in the
hope that it will be useful, but WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.
See W3C License http://www.w3.org/Consortium/Legal/ for more details.

*/

#ifndef test_nodeentityreferencenodetype
#define test_nodeentityreferencenodetype

#include "dom_conf_test.hpp"

/**
 *     The "getNodeType()" method for an EntityReference Node
 *     returns the constant value 5.
 *     
 *     Retrieve the EntityReference node from the last child
 *     of the second employee and invoke the "getNodeType()"   
 *     method.   The method should return 5. 
* @author NIST
* @author Mary Brady
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-111237558">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-111237558</a>
*/

template<class string_type, class string_adaptor>
class nodeentityreferencenodetype : public DOMTestCase<string_type, string_adaptor> 
{
   public: 
     nodeentityreferencenodetype(std::string name) : DOMTestCase(name)
     {

       //   check if loaded documents are supported for content type
       const std::string contentType = getContentType();
    preload(contentType, "staff", false);
    }

  typedef typename DOMTestCase<string_type, string_adaptor> baseT;
  using baseT::DOMImplementation;
  using baseT::Document; 
  using baseT::DocumentType;
  using baseT::DocumentFragment; 
  using baseT::Node;
  using baseT::Element;
  using baseT::Attr;
  using baseT::NodeList;
  using baseT::NamedNodeMap;
  using baseT::Entity;
  using baseT::EntityReference;
  using baseT::CharacterData;
  using baseT::CDATASection;
  using baseT::Text;
  using baseT::Comment;
  using baseT::ProcessingInstruction;
  using baseT::Notation;

  typedef typename Arabica::DOM::DOMException DOMException;
  typedef string_type String;
  typedef string_adaptor SA;
  typedef bool boolean;

   /*
    * Runs the test case.
    */
   void runTest()
   {
      Document doc;
      NodeList elementList;
      Element entRefAddr;
      Node entRefNode;
      int nodeType;
      doc = (Document) load("staff", false);
      elementList = doc.getElementsByTagName(SA::construct_from_utf8("address"));
      entRefAddr = (Element) elementList.item(1);
      entRefNode = entRefAddr.getFirstChild();
      nodeType = (int) entRefNode.getNodeType();
      
      if (equals(3, nodeType)) {
          entRefNode = doc.createEntityReference(SA::construct_from_utf8("ent2"));
      assertNotNull(entRefNode);
      nodeType = (int) entRefNode.getNodeType();
      }
    assertEquals(5, nodeType);
  
   }
  
   /*
    *  Gets URI that identifies the test.
    */
   std::string getTargetURI() const
   {
      return "http://www.w3.org/2001/DOM-Test-Suite/level1/core/nodeentityreferencenodetype";
   }
};

#endif