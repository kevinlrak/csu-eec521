// File:        DRESS/utilities/WebServer/WebServer.h
// Authors:     Kevin Rak
// Description: This is the WebServer definition file. It is responsible for
//              defining the abstract WebServer class and a static Create method.

#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <cstdint>
#include <memory>

namespace DRESS {

	/*!
	 * \brief The WebServer class
	 */
	class WebServer {
	public:
		using ptr_t = std::shared_ptr<WebServer>;

		/*!
		 * \brief CreateWebServer creates a concrete implementation
		 * \param port Optional parameter to specify a non-standard port for the server
		 * \return A shared pointer to the new concrete WebServer
		 */
		static ptr_t CreateWebServer(int Port = 80, std::string DocumentRoot = std::string());

		virtual ~WebServer() = default;

		/*!
		 * \brief RegisterGetFileHandler
		 * \param URI
		 * \param FilePath
		 */
		virtual void RegisterGetFileHandler(std::string URI, std::string FilePath) = 0;

		/*!
		 * \brief RegisterGetJsonHandler
		 * \param URI
		 */
		virtual void RegisterGetJsonHandler(std::string URI, std::string(*GetJsonObject)()) = 0;

		/*!
		 * \brief RegisterPostJsonHandler
		 * \param URI
		 */
		virtual void RegisterPostJsonHandler(std::string URI, void(*PostJsonObject)(const std::string & JsonObject)) = 0;

	};

}

#endif // WEBSERVER_H
