require_relative 'xmlDsl'
require_relative 'class_data'

classTest = ClassData.new("XptoClass")
classTest.methods.push("methodOne")
classTest.methods.push("methodTwo")
classTest.attributes.push("attr1")
classTest.attributes.push("attr2")
classTest.constructors.push("initialize")

def generate_class(xml, classData)
  xml.classData :name => classData.name do
    classData.methods.each do |m|
      generate_method(xml, m)
    end
    classData.attributes.each do |a|
      generate_attribute(xml, a)
    end
  end
end

def generate_attribute(xml, pAttribute)
  xml.attributeData :name => pAttribute
end

def generate_method(xml, pMethodData)
    xml.methodData :name => pMethodData
end

builder = XML::XMLBuilder.new

generate_class(builder, classTest)
puts builder.tag
