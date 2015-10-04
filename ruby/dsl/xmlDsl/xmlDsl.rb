require 'singleton'

module XML

  class XMLBuilder

    attr_reader :tag
    attr_reader :betweenTag

    private

      def initialize
        @tag = ''
        @content = ''
      end

      def method_missing(pTagName, *pTagParameters, &block)
        currentTagName = "<#{pTagName.to_s}"
        @tag << currentTagName

        if pTagParameters.size > 0 and pTagParameters[0].is_a? Hash
          pTagParameters[0].each do |key, value|
            @tag << " #{key.to_s}=\"#{value.to_s}\""
          end
        end

        if block_given?
          @tag << ">\n"
          result = instance_eval(&block)
          @content = result if result
          @tag << @content
          @tag << "\n</#{pTagName.to_s}>\n"
        else
          @tag << "/>\n"
        end
          @content = ''
      end

      def to_s
        @tag
      end

      def self.instance
        @@instance ||= new
      end
  end
end

def xml
  XML::XMLBuilder.instance
end
