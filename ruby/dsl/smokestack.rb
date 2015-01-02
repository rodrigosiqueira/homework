#This example was extracted from:
# http://robots.thoughtbot.com/writing-a-domain-specific-language-in-ruby

module Smokestack
  @registry = {}

  def self.registry
    @registry
  end
  
  # Fabric based on DefinitionProxy (defined below). Notice the instace_eval
  # this is the huge trick here, instance_eval will evaluate the block passed
  # to it.
  def self.define(&block)
    definition_proxy = DefinitionProxy.new
    definition_proxy.instance_eval(&block)
  end

  # Method that build the factory, this is the final tie between everything.
  # Here factory will register the factory class.
  # The second parameter represent an extra option
  # other_user = Smokestack.build(User, name: 'Bob')
  def self.build(factory_class, overrides = {})
    instance = factory_class.new
    factory = registry[factory_class]
    attributes = factory.attributes.merge(overrides)
    attributes.each do |attribute_name, value|
      instance.send("#{attribute_name}=", value)
    end
    instance
  end
end

# See Factory class below
class DefinitionProxy
  def factory(factory_class, &block)
    factory = Factory.new
    factory.instance_eval(&block)
    Smokestack.registry[factory_class] = factory
  end
end

class Factory < BasicObject
  def initialize
    @attributes = {}
  end

  attr_reader :attributes

  def method_missing(name, *args, &block)
    @attributes[name] = args[0]
  end
end

