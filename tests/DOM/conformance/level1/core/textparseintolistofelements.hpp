#ifndef test_textparseintolistofelements
#define test_textparseintolistofelements


/*
This C++ source file was generated for Arabica
from the source document contained in the W3C
DOM Conformance Test Suite.
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
/**
 *     Retrieve the textual data from the last child of the 
 *     second employee.   That node is composed of two   
 *     EntityReference nodes and two Text nodes.   After
 *     the content node is parsed, the "address" Element
 *     should contain four children with each one of the
 *     EntityReferences containing one child.
* @author NIST
* @author Mary Brady
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-1451460987">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-1451460987</a>
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-11C98490">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-11C98490</a>
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-745549614">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-745549614</a>
*/

template<class string_type, class string_adaptor>
class textparseintolistofelements : public DOMTestCase<string_type, string_adaptor> 
{
    typedef DOMTestCase<string_type, string_adaptor> baseT;
   public: 
     textparseintolistofelements(std::string name) : baseT(name)
     {

       //   check if loaded documents are supported for content type
       const std::string contentType = baseT::getContentType();
    baseT::preload(contentType, "staff", false);
    }

  typedef typename Arabica::DOM::DOMImplementation<string_type, string_adaptor>  DOMImplementation;
  typedef typename Arabica::DOM::Document<string_type, string_adaptor> Document; 
  typedef typename Arabica::DOM::DocumentType<string_type, string_adaptor> DocumentType;
  typedef typename Arabica::DOM::DocumentFragment<string_type, string_adaptor> DocumentFragment; 
  typedef typename Arabica::DOM::Node<string_type, string_adaptor> Node;
  typedef typename Arabica::DOM::Element<string_type, string_adaptor> Element;
  typedef typename Arabica::DOM::Attr<string_type, string_adaptor> Attr;
  typedef typename Arabica::DOM::NodeList<string_type, string_adaptor> NodeList;
  typedef typename Arabica::DOM::NamedNodeMap<string_type, string_adaptor> NamedNodeMap;
  typedef typename Arabica::DOM::Entity<string_type, string_adaptor> Entity;
  typedef typename Arabica::DOM::EntityReference<string_type, string_adaptor> EntityReference;
  typedef typename Arabica::DOM::CharacterData<string_type, string_adaptor> CharacterData;
  typedef typename Arabica::DOM::CDATASection<string_type, string_adaptor> CDATASection;
  typedef typename Arabica::DOM::Text<string_type, string_adaptor> Text;
  typedef typename Arabica::DOM::Comment<string_type, string_adaptor> Comment;
  typedef typename Arabica::DOM::ProcessingInstruction<string_type, string_adaptor> ProcessingInstruction;
  typedef typename Arabica::DOM::Notation<string_type, string_adaptor> Notation;

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
      Node addressNode;
      NodeList childList;
      Node child;
      int length;
      String value;
      Node grandChild;
      std::vector<string_type> result;
      
      std::vector<string_type> expectedNormal;
      expectedNormal.push_back(SA::construct_from_utf8("1900 Dallas Road"));
      expectedNormal.push_back(SA::construct_from_utf8(" Dallas, "));
      expectedNormal.push_back(SA::construct_from_utf8("Texas"));
      expectedNormal.push_back(SA::construct_from_utf8("\n 98554"));
      
      std::vector<string_type> expectedExpanded;
      expectedExpanded.push_back(SA::construct_from_utf8("1900 Dallas Road Dallas, Texas\n 98554"));
      
      doc = (Document) baseT::load("staff", false);
      elementList = doc.getElementsByTagName(SA::construct_from_utf8("address"));
      addressNode = elementList.item(1);
      childList = addressNode.getChildNodes();
      length = (int) childList.getLength();
      for (unsigned int indexN65663 = 0; indexN65663 != childList.getLength(); indexN65663++) {
          child = (Node) childList.item(indexN65663);
    value = child.getNodeValue();
      
      if ((baseT::isNull(value))) {
          grandChild = child.getFirstChild();
      baseT::assertNotNull(grandChild, __LINE__, __FILE__);
      value = grandChild.getNodeValue();
      result.push_back(value);
      } else {
          result.push_back(value);
      }
        
      }
      
      if (baseT::equals(4, length)) {
          baseT::assertEquals(expectedNormal, result, __LINE__, __FILE__);
  } else {
          baseT::assertEquals(expectedExpanded, result, __LINE__, __FILE__);
  }
        
    
   }
  
   /*
    *  Gets URI that identifies the test.
    */
   std::string getTargetURI() const
   {
      return "http://www.w3.org/2001/DOM-Test-Suite/level1/core/textparseintolistofelements";
   }
};

#endif
