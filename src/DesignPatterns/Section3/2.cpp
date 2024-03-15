//groovy style builder

#include <string>
#include <vector>
#include <iostream>

using namespace std;

namespace html 
{
  struct Tag
  {
    std::string name;
    std::string text;
    std::vector<Tag> children;
    std::vector<std::pair<std::string, std::string>> attributes;

    // we define the stream output operator on the tag to print all the tags, including all the children and all the content correctly.
    friend std::ostream& operator<<(std::ostream& os, const Tag& tag)
    {
      os << "<" << tag.name;

      for (const auto& att : tag.attributes)
        os << " " << att.first << "=\"" << att.second << "\"";

      if (tag.children.size() == 0 && tag.text.length() == 0)
      {
        os << "/>" << std::endl;
      } 
      else
      {
        os << ">" << std::endl;

        if (tag.text.length())
          os << tag.text << std::endl;

        for (const auto& child : tag.children)
          os << child;

        os << "</" << tag.name << ">" << std::endl;
      }

      return os;
    }

    // So we have the tag, we're going to add a couple of constructors. I'm actually going to make them protected, so we're going to have just a couple of constructors.
    //First of all, we'll have a constructor which initializes the tag using the name as well as the text.
  protected:
    //we have 2 argumenst: the construct name the tag (const std::string& name) and a vector reference for the children
    Tag(const std::string& name, const std::string& text)
      : name{name}
      , text{text}
    {
    }

    Tag(const std::string& name, const std::vector<Tag>& children)
      : name{name},
        children{children}
    {
    }
  };

  //define a paragraph P as an inherited class
  struct P : Tag
  {
    explicit P(const std::string& text)
      : Tag{"p", text}
    {
    }

    // use an initializer list of type tags. So this tag, the tag P is going to take in its constructor a bunch of other tags.children is a vector of type Tag :
    //see it from: Tag(const std::string& name, const std::vector<Tag>& children) above
    P(std::initializer_list<Tag> children)
      : Tag("p", children)
    {
    }
    
  };


  struct IMG : Tag
  {
    explicit IMG(const std::string& url)
      : Tag{"img", ""}
    {
      attributes.emplace_back(make_pair("src", url));
    }
  };
}

int main1()
{
  using namespace html;

  std::cout <<

    P {
      IMG {"http://pokemon.com/pikachu.png"}
    }

    << std::endl;

  getchar();
  return 0;
}