
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

#ifndef test_documentcreateentityreferenceknown
#define test_documentcreateentityreferenceknown

#include "dom_conf_test.hpp"

/**
 *     The "createEntityReference(name)" method creates an 
 *    EntityReference node.  In addition, if the referenced entity
 *    is known, the child list of the "EntityReference" node
 *    is the same as the corresponding "Entity" node.
 *    
 *    Retrieve the entire DOM document and invoke its 
 *    "createEntityReference(name)" method.  It should create 
 *    a new EntityReference node for the Entity with the 
 *    given name.  The referenced entity is known, therefore the child
 *    list of the "EntityReference" node is the same as the corresponding
 *    "Entity" node.
* @author NIST
* @author Mary Brady
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-392B75AE">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-392B75AE</a>
*/

template<class string_type, class string_adaptor>
class documentcreateentityreferenceknown : public DOMTestCase<string_type, string_adaptor> 
{
   public: 
     documentcreateentityreferenceknown(std::string name) : DOMTestCase(name)
     {

       //   check if loaded documents are supported for content type
       const std::string contentType = getContentType();
    preload(contentType, "staff", true);
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
      EntityReference newEntRefNode;
      NodeList newEntRefList;
      Node child;
      String name;
      String value;
      doc = (Document) load("staff", true);
      newEntRefNode = doc.createEntityReference(SA::construct_from_utf8("ent3"));
      assertNotNull(newEntRefNode);
      newEntRefList = newEntRefNode.getChildNodes();
      assertSize(1, newEntRefList);
      child = newEntRefNode.getFirstChild();
      name = child.getNodeName();
      assertEquals("#text", name);
  value = child.getNodeValue();
      assertEquals("Texas", value);
  
   }
  
   /*
    *  Gets URI that identifies the test.
    */
   std::string getTargetURI() const
   {
      return "http://www.w3.org/2001/DOM-Test-Suite/level1/core/documentcreateentityreferenceknown";
   }
};

#endif